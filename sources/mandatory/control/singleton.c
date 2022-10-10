/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:32:32 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 16:44:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_minishell	*c(void)
{
	static t_minishell	__control_instance;

	return (&__control_instance);
}

void	initialize_control(int argc, char **argv, char **envp)
{
	c()->debug = false;
	c()->argc = argc;
	c()->argv = argv;
	c()->envp = envp;
}

void	deinitialize_control(void)
{
	ft_bzero(c(), sizeof(t_minishell));
}
