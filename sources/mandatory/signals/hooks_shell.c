/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:51:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 18:28:22 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	set_interrupt_signal_hook(void)
{
	set_signal_hook(signal_action(), handle_interrupt_signal, SIGINT);
}

static void	set_quit_signal_hook(void)
{
	set_signal_hook(signal_action(), SIG_IGN, SIGQUIT);
}

void	set_interactive_shell_hooks(void)
{

	set_interrupt_signal_hook();
	set_quit_signal_hook();
}
