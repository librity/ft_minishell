/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:28:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 21:01:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pipe_or_die(int pipe_fds[2])
{
	int	pipe_return;

	pipe_return = pipe(pipe_fds);
	if (pipe_return < 0)
		die(PIPE_ERR);
}

void	close_pipe(int pipe_fds[2])
{
	close_or_die(pipe_fds[PIPE_READ]);
	close_or_die(pipe_fds[PIPE_WRITE]);
}
