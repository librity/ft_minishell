/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:51:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:36:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_fork_interrupt_signal(int signal)
{
	ft_bdebug(debug(),
		"handle_fork_interrupt_signal: signal: %d", signal);
	quit();
}

static void	handle_fork_quit(int signal)
{
	ft_bdebug(debug(), "handle_fork_quit: signal: %d", signal);
	printf(FORK_QUIT_MSG);
	quit();
}

static void	set_interrupt_fork_signal_hook(void)
{
	set_signal_hook(signal_action(), handle_fork_interrupt_signal, SIGINT);
}

static void	set_quit_fork_signal_hook(void)
{
	set_signal_hook(signal_action(), handle_fork_quit, SIGQUIT);
}

void	set_fork_hooks(void)
{
	set_interrupt_fork_signal_hook();
	set_quit_fork_signal_hook();
}
