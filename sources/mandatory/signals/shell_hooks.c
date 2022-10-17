/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:51:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:37:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_interrupt_signal(int signal)
{
	if (debug())
		ft_debug("handle_interrupt_signal: signal: %d", signal);
	else
		printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	set_interrupt_signal_hook(void)
{
	set_signal_hook(signal_action(), handle_interrupt_signal, SIGINT);
}

void	set_interactive_shell_hooks(void)
{
	set_interrupt_signal_hook();
	disable_quit_signal();
}
