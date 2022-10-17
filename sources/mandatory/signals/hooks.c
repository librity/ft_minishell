/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:11:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:12:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	disable_interrupt_signal(void)
{
	set_signal_hook(signal_action(), SIG_IGN, SIGINT);
}

void	disable_quit_signal(void)
{
	set_signal_hook(signal_action(), SIG_IGN, SIGQUIT);
}
