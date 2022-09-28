/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 08:51:51 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_child(t_parse_list *pipeline, int pipe[2])
{
	stdout_to_pipe(pipe);
	close_pipe(pipe);
	handle_pipe_sequence(pipeline);
}

void	execute_pipe(t_parse_list *pipeline)
{
	pid_t	pid;
	int		pipe[2];

	pipe_or_die(pipe);
	pid = fork_or_die();
	if (pid == CHILD_PROCESS_ID)
		handle_child(pipeline, pipe);
	pipe_to_stdin(pipe);
	close_pipe(pipe);
	waitpid(pid, NULL, 0);
}
