/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_multiple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/16 20:28:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	spawn_first_pipe(t_parse_list *pipeline, pid_t *pids, int **pipes)
{
	pids[0] = fork_or_die();
	if (pids[0] != CHILD_PROCESS_ID)
		return ;
	stdout_to_pipe(pipes[0]);
	close_pipes(pipes);
	handle_fork_sequence(pipeline);
}

static void	spawn_pipe(t_parse_list *pipeline,
						pid_t *pids,
						int **pipes,
						int index)
{
	int	*in_pipe;
	int	*out_pipe;

	pids[index] = fork_or_die();
	if (pids[index] != CHILD_PROCESS_ID)
		return ;
	in_pipe = pipes[index - 1];
	out_pipe = pipes[index];
	pipe_to_stdin(in_pipe);
	stdout_to_pipe(out_pipe);
	close_pipes(pipes);
	handle_fork_sequence(pipeline);
}

static void	spawn_last_pipe(t_parse_list *pipeline,
							pid_t *pids,
							int **pipes,
							int index)
{
	int	*in_pipe;

	pids[index] = fork_or_die();
	if (pids[index] != CHILD_PROCESS_ID)
		return ;
	in_pipe = pipes[index - 1];
	pipe_to_stdin(in_pipe);
	close_pipes(pipes);
	handle_fork_sequence(pipeline);
}

void	spawn_multiple_pipes(t_execute_pl *ctl, t_parse_list *pipeline)
{
	int	index;

	spawn_first_pipe(pipeline, ctl->pids, ctl->pipes);
	pipeline = find_next_parse_pipe(pipeline)->next;
	index = 1;
	while (index < ctl->pipe_count)
	{
		spawn_pipe(pipeline, ctl->pids, ctl->pipes, index);
		pipeline = find_next_parse_pipe(pipeline)->next;
		index++;
	}
	spawn_last_pipe(pipeline, ctl->pids, ctl->pipes, index);
	close_pipes(ctl->pipes);
}
