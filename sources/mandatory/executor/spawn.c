/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 14:07:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	spawn_single_pipe(t_parse_list *pipeline, pid_t *pids)
{
	pids[0] = fork_or_die();
	if (pids[0] != CHILD_PROCESS_ID)
		return ;
	handle_fork_sequence(pipeline);
}

void	spawn_pipes(t_execute_pl *ctl, t_parse_list *pipeline)
{
	set_fork_hooks();
	if (has_heredoc(pipeline))
		disable_signals();
	if (ctl->pipe_count == 0)
	{
		spawn_single_pipe(pipeline, ctl->pids);
		return ;
	}
	spawn_multiple_pipes(ctl, pipeline);
}
