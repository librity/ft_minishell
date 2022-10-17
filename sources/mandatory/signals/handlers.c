/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:54:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:21:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_interrupt_signal(int signal)
{
	if (debug())
		ft_debug("handle_interrupt_signal: signal: %d", signal);
	else
		printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_fork_interrupt_signal(int signal)
{
	ft_bdebug(debug(),
		"handle_fork_interrupt_signal: signal: %d", signal);
	quit();
}

void	handle_fork_quit(int signal)
{
	ft_bdebug(debug(), "handle_fork_quit: signal: %d", signal);
	printf(FORK_QUIT_MSG);
	quit();
}
