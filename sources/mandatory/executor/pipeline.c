/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/16 01:36:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	initialize_pipeline(t_execute_pl *ctl, t_parse_list *pipeline)
{
	int	i;

	ctl->pipe_count = count_parse_pipes(pipeline);
	ctl->pid_count = ctl->pipe_count + 1;
	ctl->pids = ft_clalloc(lalloc(), sizeof(pid_t), ctl->pid_count);
	ctl->pipes = ft_clalloc(lalloc(), sizeof(int *), ctl->pipe_count + 1);
	i = 0;
	while (i < ctl->pipe_count)
	{
		ctl->pipes[i] = ft_clalloc(lalloc(), sizeof(int), 2);
		pipe_or_die(ctl->pipes[i]);
		i++;
	}
	ctl->pipes[i] = NULL;
}

void	wait_for_all(pid_t *pids, int pid_count)
{
	int	index;
	int	fork_status;
	int	exit_status;

	index = 0;
	while (index < pid_count)
	{
		waitpid_or_die(pids[index], &fork_status, 0);
		exit_status = WEXITSTATUS(fork_status);
		set_last_exit(exit_status);
		index++;
	}
}

void	execute_pipeline(t_parse_list *pipeline)
{
	t_execute_pl	ctl;

	initialize_pipeline(&ctl, pipeline);
	spawn_pipes(&ctl, pipeline);
	wait_for_all(ctl.pids, ctl.pid_count);
}
