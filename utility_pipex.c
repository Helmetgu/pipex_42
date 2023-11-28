/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:31:49 by mlow              #+#    #+#             */
/*   Updated: 2023/11/22 02:46:49 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_read_write_end(int *pipe_fd, int input, int outfile, int array)
{
	if (array == 2)
	{
		close(pipe_fd[0]);
		if (dup2(input, 0) == -1)
			perror_function("dup2 for infile failed, check code", 1);
		if (dup2(pipe_fd[1], 1) == -1)
			perror_function("dup2 for pip_fd[1](for child process) failed", 1);
	}
	else if (array == 3)
	{
		if (dup2(input, 0) == -1)
			perror_function("dup2 for outfile failed, check code", 1);
		if (dup2(outfile, 1) == -1)
			perror_function("dup2 for pip_fd[0](for child process) failed", 1);
	}
	else
		perror_function("Fail @ close_read_write_end", 1);
}

void	close_write_read_end(char **argv, int *pipe_fd, int array, char **envp)
{
	wait(NULL);
	close(pipe_fd[1]);
	if (array == 2)
		process_handler(argv, pipe_fd[0], 3, envp);
}
//----------------------------------------------------------------

void	free_str_cmd(char **str_cmd1, char **str_cmd2, char *message, int exit)
{
	int	array;

	array = 0;
	if (str_cmd1)
	{
		while (str_cmd1[array])
		{
			free(str_cmd1[array]);
			array++;
		}
		free(str_cmd1);
	}
	array = 0;
	if (str_cmd2)
	{
		while (str_cmd2[array])
		{
			free(str_cmd2[array]);
			array++;
		}
		free(str_cmd2);
	}
	if (exit != 0)
		perror_function(message, exit);
}

char	*get_path(char *name, char **envp)
{
	char	*path_directories;
	char	*tmp_path;
	int		index;
	int		array;
	int		name_strlen;

	array = 0;
	path_directories = (char *)malloc(sizeof(char) * 1);
	if (!path_directories)
		return (NULL);
	path_directories[0] = '\0';
	while (envp[array])
	{
		name_strlen = ft_strlen(name);
		if (ft_strncmp(envp[array], name, name_strlen) == 0)
		{
			index = name_strlen;
			tmp_path = path_directories;
			path_directories = ft_strjoin(tmp_path, (envp[array] + index));
			free(tmp_path);
			return (path_directories);
		}
		array++;
	}
	return (NULL);
}

char	*ft_exec(char *argv_cmd, char **envp)
{
	char	**string_command;
	char	**path_directories;
	char	*path_array;
	char	*exec;
	int		array;

	string_command = ft_split(argv_cmd, ' ');
	path_array = get_path("PATH=", envp);
	path_directories = ft_split(path_array, ':');
	free(path_array);
	array = -1;
	while (path_directories[++array] && path_directories)
	{
		path_array = ft_strjoin(path_directories[array], "/");
		exec = ft_strjoin(path_array, string_command[0]);
		free(path_array);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_str_cmd(string_command, path_directories, NULL, 0);
			return (exec);
		}
		free(exec);
	}
	free_str_cmd(string_command, path_directories, "fail to find command", 1);
	return (NULL);
}
//
//this will be used to support pipex.c
//
/*
#include "pipex.h"

//remember, fd[3] is the infile
void	close_read_write_end(int *pipe_fd, int input, int outfile, int array)
{
	printf("Close_read_write_end tester 0\n");
	if (array == 2)//2 if condition for array
	{
		printf("Close_read_write_end tester 1\n");
		close(pipe_fd[0]);// closes fd[4] read end
		if (dup2(input, 0) == -1)//infile->fd[3] -> new_fd= fd[0]
			perror_function("dup2 for infile failed, check code", 1);
		printf("Close pipe_fd[0] & dup2 tester 2\n");
		//printf still works here
		if (dup2(pipe_fd[1], 1) == -1)
			perror_function("dup2 for pip_fd[1](for child process) failed", 1);
		//why this wont print?	
		printf("Test working failed at close_read_write_end 3\n");
		//cause after the dup2(pipe_fd[1]), it is piped?
	}
	else if (array == 3)
	{
		if (dup2(input, 0) == -1)
			perror_function("dup2 for outfile failed, check code", 1);
		if (dup2(outfile, 1) == -1)
			perror_function("dup2 for pip_fd[0](for child process) failed", 1);
	//printf("Test working failed at close_read_write_end 5\n");//why this outfile?
	}
	else
		perror_function("Fail @ close_read_write_end", 1);
}

void	close_write_read_end(char **argv, int *pipe_fd, int array, char **envp)
{
	printf("Start of parent process!");
	wait(NULL);
	printf("after wait(NULL of parent process) && before close pipe_fd");
	close(pipe_fd[1]);
	printf("after close pipe_fd");
	if (array == 2)
		process_handler(argv, pipe_fd[0], 3, envp);
}

//also in the code:
//dup2(fd, STDIN_FILENO);
//i wrote dup2(fd, 0) instead, is it the same or is the first one better?
//"Answer, yes both are the same. It is just for reability."
//
//----------------------------------------------------------------

void	free_str_cmd(char **str_cmd1, char **str_cmd2, char *message, int exit)
{
	int	array;

	array = 0;
	if (str_cmd1)
	{
		while (str_cmd1[array])
		{
			free(str_cmd1[array]);
			array++;
		}
		free(str_cmd1);
	}
	array = 0;
	if (str_cmd2)
	{
		while (str_cmd2[array])
		{
			free(str_cmd2[array]);
			array++;
		}
		free(str_cmd2);
	}
	if (exit != 0)
		perror_function(message, exit);
}

//note: *name = "PATH=".
char	*get_path(char *name, char **envp)//free get_path @ ft_exec once used.
{
	//getting the value of the PATH_location & name = "PATH=";
	char	*path_directories;
	char	*tmp_path;
	int		index;
	int		array;
	int		name_strlen;

	array = 0;
	path_directories = (char *)malloc(sizeof(char) * 1);
	if (!path_directories)
		return (NULL);
	path_directories[0] = '\0';
	while (envp[array])
	{
		name_strlen = ft_strlen(name);//value would be '5'
		if (ft_strncmp(envp[array], name, name_strlen) == 0)
		{
			index = name_strlen;//value would be '5'
			tmp_path = path_directories;
			path_directories = ft_strjoin(tmp_path, (envp[array] + index));
			free(tmp_path);
			return (path_directories);
		}
		array++;
	}
	return (NULL);
}
//int execve(const char *pathname, 
//char *const _Nullable argv[], char *const _Nullable envp[]);
//
//1)SYSTEMD_EXEC_PID=974651
//2)PATH=/home/mlow/bin:
///usr/local/sbin:/usr/local/bin:/usr/sbin:
///usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
//
//3)after that ft_split them at the ":" part
//4)After that, checks if argv[1] has the command:
//5)/usr/local/bin/"ls"
//6)learn about ->access() and how to use.
//

char	*ft_exec(char *argv_cmd, char **envp)//free 
{
	char	**string_command;
	char	**path_directories;
	char	*path_array;
	char	*exec;
	int		array;

	string_command = ft_split(argv_cmd, ' ');
	//to seperate commands by arrays eg "wc -ls"
	//note: because str_cmd used ft_split, it has malloc inside, free.
	path_array = get_path("PATH=", envp);
	//got "path locations" & split
	//(int)access(const char *pathname, int mode);
	//note: because path_array has get_path, it has malloc, free
	path_directories = ft_split(path_array, ':');
	free(path_array);//freeing get_path, can be reused below
	array = -1;//to reduce lines used.
	//++array to start with 0 first cause array++ means we start at -1.
	while (path_directories[++array] && path_directories)
	{
		//first you must add '/' in front, e.g /home/usr/bin'/' then "ls"
		path_array = ft_strjoin(path_directories[array], "/");
		//must "" cause string
		//now path_array's job is done-
		exec = ft_strjoin(path_array, string_command[0]);
		// we just need to find argv_cmd[0] 
		//cause the "-ls" is also inside that wc part.
		//what happens is that after finding "ls", the second
		// "-l" is located inside that folder
		free(path_array);
		//free for next's or final path_array
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_str_cmd(string_command, path_directories, NULL, 0);
			return (exec);
		}
		free(exec);
	}
	free_str_cmd(string_command, path_directories, "fail to find command", 1);
	return (NULL);
}
*/
