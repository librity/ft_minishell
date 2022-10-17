/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocking_execve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:34:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/15 19:59:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc blocking_execve.c && ./a.out

#include <unistd.h>
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

void handle_cat(int pipe_fds[2], char **envp)
{
	stdout_to_pipe(pipe_fds);
	close_pipe(pipe_fds);
	if (execve("/usr/bin/cat", (char *[]){"/usr/bin/cat", NULL}, envp))
		printf("execve ERROR!");
}

void handle_ls(char **envp)
{
	if (execve("/usr/bin/ls", (char *[]){"/usr/bin/ls", NULL}, envp))
		printf("execve ERROR!");
}

int main(int argc, char **argv, char **envp)
{
	pid_t pid;
	int pipe_fds[2];

	pipe(pipe_fds);
	pid = fork();
	if (pid == CHILD_PROCESS_ID)
		handle_cat(pipe_fds, envp);
	pipe_to_stdin(pipe_fds);
	close_pipe(pipe_fds);
	waitpid(pid, NULL, 0);

	pid = fork();
	if (pid == CHILD_PROCESS_ID)
		handle_ls(envp);
	waitpid(pid, NULL, 0);

	return (0);
}
