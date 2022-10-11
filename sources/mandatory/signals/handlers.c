/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:54:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 14:39:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_interrupt_signal(int signal)
{
	ft_bdebug(debug(), "DEBUG: handle_interrupt_signal: signal: %d", signal);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_fork_interrupt_signal(int signal)
{
	ft_bdebug(debug(),
		"DEBUG: handle_fork_interrupt_signal: signal: %d", signal);
	exit (0);
}

void	handle_fork_quit(int signal)
{
	ft_bdebug(debug(), "DEBUG: handle_fork_quit: signal: %d", signal);
	printf("[1]+   quit       ./minishell\n");
	exit(0);
}

