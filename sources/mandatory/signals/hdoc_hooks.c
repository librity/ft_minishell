/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:35:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:37:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_hdoc_interrupt_signal(int signal)
{
	if (debug())
		ft_debug("handle_hdoc_interrupt_signal: signal: %d", signal);
	else
		printf("\n");
	quit();
}

static void	set_interrupt_hdoc_signal_hook(void)
{
	set_signal_hook(signal_action(), handle_hdoc_interrupt_signal, SIGINT);
}

void	set_hdoc_hooks(void)
{
	set_interrupt_hdoc_signal_hook();
}
