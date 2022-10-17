/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:13:32 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 10:17:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_proc_fds	*ioe(void)
{
	return (&c()->ioe);
}

int	ioe_in(void)
{
	return (c()->ioe.input);
}

int	ioe_out(void)
{
	return (c()->ioe.input);
}

int	ioe_err(void)
{
	return (c()->ioe.error);
}
