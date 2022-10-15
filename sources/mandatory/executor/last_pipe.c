/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 19:57:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_last_child(t_parse_list *pipeline)
{
	fork_handle_pipe_sequence(pipeline);
}

void	execute_last_pipe(t_parse_list *pipeline)
{
	pid_t	pid;
	int		fork_status;
	int		exit_status;

	pid = fork_or_die();
	if (pid == CHILD_PROCESS_ID)
		handle_last_child(pipeline);
	waitpid_or_die(pid, &fork_status, 0);
	exit_status = WEXITSTATUS(fork_status);
	set_last_exit(exit_status);
}
