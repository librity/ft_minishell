/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 20:29:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_last_child(t_parse_list *pipeline)
{
	handle_pipe_sequence(pipeline);
}

void	execute_last_pipe(t_parse_list *pipeline)
{
	pid_t	pid;

	pid = fork_or_die();
	if (pid == CHILD_PROCESS_ID)
		handle_last_child(pipeline);
	waitpid(pid, NULL, 0);
}
