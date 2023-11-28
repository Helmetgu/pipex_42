/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:16:54 by mlow              #+#    #+#             */
/*   Updated: 2023/11/23 19:19:49 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_function(char *message, int exit_code)
{
	if (exit_code == 1)
	{
		perror(message);
		exit(exit_code);
	}
	else
		exit(exit_code);
}

void	perror_scmd_path(char *message, int exit, char **s_cmd, char *path)
{
	int	array;

	array = 0;
	while (s_cmd[array])
	{
		free(s_cmd[array]);
		array++;
	}
	free(s_cmd);
	free(path);
	perror_function(message, exit);
}

void	process_handler(char **argv, int input, int array, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		outfile;
	char	*path;
	char	**s_cmd;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		perror_function("Unable to open outfile", 1);
	if (pipe(pipe_fd) == -1)
		perror_function("Pipe failed, Check code", 1);
	pid = fork();
	if (pid < 0)
		perror_function("Fork failed", 1);
	if (pid == 0)
	{
		close_read_write_end(pipe_fd, input, outfile, array);
		path = ft_exec(argv[array], envp);
		s_cmd = ft_split(argv[array], ' ');
		if (path != NULL)
			execve(path, s_cmd, envp);
	}
	else
		close_write_read_end(argv, pipe_fd, array, envp);
	close(outfile);
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;

	if (argc != 5)
	{
		write(2, "Please re-enter 4 Arguments.\n", 29);
		return (1);
	}
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("Unable to open infile");
		return (1);
	}
	process_handler(argv, infile, 2, envp);
	close(infile);
	return (0);
}
//
//Almost to tester~
/*
 How do we start with pipex? we create the file pipex.c first.
What should pipex.c do?:
1) implement the following:
- create pipes; fork process to execute cmd1 & cmd2; 
  use execve on child process
- manage flow of data in processes and file I/O.
*/
//Tester starts here
/*
#include "pipex.h"

void	perror_function(char *message, int exit_code)
{
	if (exit_code == 1)
	{
		perror(message);
		exit(exit_code);
	}
	else
		exit(exit_code);
}

void	perror_scmd_path(char *message, int exit, char **s_cmd, char *path)
{
	int	array;

	array = 0;
	while (s_cmd[array])
	{
		free(s_cmd[array]);
		array++;
	}
	free(s_cmd);
	free(path);
	perror_function(message, exit);
}

//int fd here is fd[3]
void	process_handler(char **argv, int input, int array, char **envp) 
{
	printf("Start of process_handler!\n");
	pid_t	pid;//represent Process IDs (PIDs) an int type. 
		    //Example: SYSTEMD_EXEC_PID=974651
	int		pipe_fd[2];//[0] read end of pipe 
				// [1] write end of pipe (size of 2)
	int		outfile;
	char	*path;
	char	**s_cmd;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//why O_WRONLY -> Open for write only.
	//why 0_CREAT -> creates the pathfile if it doesn't exist
	//why O_TRUNC -> If file exists & allows O_WRONLY, file content deteled
	//
	//0644 -> file owner(read&write), group+others(only read).
	//0- no permission for the file owner.
	//6- Read and write permission for the group (4-read, + 2-write)
	//4- Read-only permission for others.
	if (outfile == -1)
		perror_function("Unable to open outfile", 1);
	printf("After opening outfile!\n");
	if (pipe(pipe_fd) == -1)//checks if creating a pipe was successful.
		perror_function("Pipe failed, Check code", 1);
	pid = fork();
	if (pid < 0)// yes it is possible for fork() to return -1.
		perror_function("Fork failed", 1);
	if (pid == 0)//p = 0-> child, p != 0 -> parent "with the PIDs".
	{
		printf("Before entering read_write child pipe\n");
		close_read_write_end(pipe_fd, input, outfile, array);
		printf("Text goes into outfile (after read_write)\n");
		//close pipe_fd[0]
		// after writing, close pipe_fd[1] at parent process
		path = ft_exec(argv[array], envp);
		printf("Text goes into outfile (after path1)\n");
		s_cmd = ft_split(argv[array], ' ');
		printf("Text goes into outfile (after path2)\n");
		if (path != NULL)
			execve(path, s_cmd, envp);
	}
	else
		close_write_read_end(argv, pipe_fd, array, envp);//close pipe_fd[1]
	printf("AFTER the parent process & Before closing outfile\n");
	close(outfile);
	printf("After closing outfile\n");
}

int	main(int argc, char **argv, char **envp)// envp-> environment pointer
{
	int	infile;

	printf("--------------------Int main start---------------------\n");
	if (argc != 5)
	{
		write(2, "Please re-enter 4 Arguments.\n", 29);
		return (1);//Return (1) signals an error
	}
	printf("After argc != 5\n");
	// cc pipex.c && ./a.out ./infile.txt "cmd1" "cmd2" ./outfile.txt
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("Unable to open infile\n");
		return (1);//Return (1) signals an error
	}
	printf("After infile open and before process_handler\n");
	process_handler(argv, infile, 2, envp);
	printf("After process_handler before closing infile\n");
	close(infile);
	printf("---------------------END----------------------\n");
	return (0);
}
*/
