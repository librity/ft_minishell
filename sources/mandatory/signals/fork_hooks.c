/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:51:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 13:11:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_interrupt(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", ioe_out());
}

static void	handle_quit(int signal)
{
	(void)signal;
	ft_putstr_fd(FORK_QUIT_MSG, ioe_out());
}

static void	set_interrupt_hook(void)
{
	set_signal_hook(signal_action(), handle_interrupt, SIGINT);
}

static void	set_quit_hook(void)
{
	set_signal_hook(signal_action(), handle_quit, SIGQUIT);
}

void	set_fork_hooks(void)
{
	set_interrupt_hook();
	set_quit_hook();
}
