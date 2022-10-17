/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:51:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 12:56:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_interrupt(int signal)
{
	(void)signal;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	set_interrupt_hook(void)
{
	set_signal_hook(signal_action(), handle_interrupt, SIGINT);
}

void	set_interactive_shell_hooks(void)
{
	set_interrupt_hook();
	disable_quit_signal();
}
