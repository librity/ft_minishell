/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonblocking_execve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:34:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/15 20:27:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc nonblocking_execve.c && ./a.out

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define PIPE_READ 0
#define PIPE_WRITE 1

#define CHILD_PROCESS_ID 0

void pipe_to_stdin(int pipe_fds[2])
{
	dup2(pipe_fds[PIPE_READ], STDIN_FILENO);
}

void stdout_to_pipe(int pipe_fds[2])
{
	dup2(pipe_fds[PIPE_WRITE], STDOUT_FILENO);
}

void close_pipe(int pipe_fds[2])
{
	close(pipe_fds[PIPE_READ]);
	close(pipe_fds[PIPE_WRITE]);
}

void handle_cat(int out_pipe[2], char **envp)
{
	stdout_to_pipe(out_pipe);
	close_pipe(out_pipe);

	execve("/usr/bin/cat", (char *[]){"/usr/bin/cat", NULL}, envp);
	printf("execve ERROR!");
	exit(EXIT_FAILURE);
}

void handle_ls(int in_pipe[2], char **envp)
{
	pipe_to_stdin(in_pipe);
	close_pipe(in_pipe);

	execve("/usr/bin/ls", (char *[]){"/usr/bin/ls", NULL}, envp);
	printf("execve ERROR!");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **envp)
{
	pid_t pid[2];
	int pipe_fds[2];

	pipe(pipe_fds);

	pid[0] = fork();
	if (pid[0] == CHILD_PROCESS_ID)
		handle_cat(pipe_fds, envp);

	pid[1] = fork();
	if (pid[1] == CHILD_PROCESS_ID)
		handle_ls(pipe_fds, envp);

	close_pipe(pipe_fds);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);

	return (0);
}
