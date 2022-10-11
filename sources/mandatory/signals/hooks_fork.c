/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:51:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 00:14:57 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	set_interrupt_fork_signal_hook(t_sigaction *sa)
{
	set_signal_hook(sa, handler_interrupt_signal_fork, SIGINT);
}

static void	set_quit_fork_signal_hook(t_sigaction *sa)
{
	set_signal_hook(sa, handler_sigquit_fork, SIGQUIT);
}

void	set_interactive_forks_hooks(t_sigaction *sa)
{
	printf("eu\n\n");
	set_interrupt_fork_signal_hook(sa);
	set_quit_fork_signal_hook(sa);
	while(1);
}
