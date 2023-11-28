/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:53:48 by mlow              #+#    #+#             */
/*   Updated: 2023/11/21 18:00:15 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft_project/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

//pipex.c
void	perror_function(char *message, int exit_code);
void	perror_scmd_path(char *message, int exit, char **s_cmd, char *path);
void	process_handler(char **argv, int index, int fd1, char **envp);

//utility_pipex.c
void	close_read_write_end(int *pipe_fd, int input, int outfile, int array);
void	close_write_read_end(char **argv, int *pipe_fd, int array, char **envp);
void	free_str_cmd(char **str_cmd1, char **str_cmd2, char *message, int exit);
char	*ft_exec(char *argv_cmd, char **envp);
char	*get_path(char *name, char **envp);

#endif
/*
#include <unistd.h> // for fork() / execve() / access()
#include <stdio.h> // for printf()
#include <stdlib.h> // exit()
#include <fcntl.h>
#include <sys/wait.h> // wait() / waitpid()
#include <sys/types.h> // for wait() / fork() / pid_t() / wait() / waitpid()
#include <errno.h> // for perror() 
*/
