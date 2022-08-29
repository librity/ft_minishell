/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:28:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 20:41:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	stdin_to_pipe(int pipe_fds[2])
{
	dup2(pipe_fds[PIPE_WRITE], STDIN_FILENO);
}

void	pipe_to_stdin(int pipe_fds[2])
{
	dup2(pipe_fds[PIPE_READ], STDIN_FILENO);
}
