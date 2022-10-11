/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 14:50:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_child(t_parse_list *pipeline, int pipe[2])
{
	stdout_to_pipe(pipe);
	close_pipe(pipe);
	fork_handle_pipe_sequence(pipeline);
}

void	execute_pipe(t_parse_list *pipeline)
{
	pid_t	pid;
	int		pipe[2];

	pipe_or_die(pipe);
	pid = fork_or_die();
	set_signal_hook(signal_action(), SIG_IGN, SIGINT);
	if (pid == CHILD_PROCESS_ID)
		handle_child(pipeline, pipe);
	pipe_to_stdin(pipe);
	close_pipe(pipe);
	waitpid(pid, NULL, 0);
}
