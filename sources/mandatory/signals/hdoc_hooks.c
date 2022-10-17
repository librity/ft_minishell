/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:35:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 14:12:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_interrupt(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", ioe_out());
	quit();
}

static void	set_interrupt_hook(void)
{
	set_signal_hook(signal_action(), handle_interrupt, SIGINT);
}

void	set_hdoc_hooks(void)
{
	set_interrupt_hook();
	disable_quit_signal();
}
