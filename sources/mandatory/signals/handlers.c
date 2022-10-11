/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:54:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 00:15:02 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_interrupt_signal(int signal)
{
	ft_bdebug(debug(), "DEBUG: handle_interrupt_signal: signal: %d\n", signal);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handler_interrupt_signal_fork(int sig)
{
	(void)sig;
	exit (0);
}

void	handler_sigquit_fork(int sig)
{
	(void)sig;
	printf("chegeu\n");
	exit(1);
	printf("[1]     quit       ./minishell\n");
	exit(0);
}

