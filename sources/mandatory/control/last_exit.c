/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:33:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 16:04:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*last_exit(void)
{
	return (c()->last_exit);
}

bool	initialize_last_exit(void)
{
	if (c()->last_exit != NULL)
		return (false);
	c()->last_exit = ft_itoa(DEFAULT_LAST_EXIT);
	return (true);
}

bool	destroy_last_exit(void)
{
	if (c()->last_exit == NULL)
		return (false);
	ft_strdel(&c()->last_exit);
	return (true);
}

bool	set_last_exit(int exit_status)
{
	if (exit_status < 0)
		return (false);
	if (c()->last_exit != NULL)
		ft_strdel(&c()->last_exit);
	c()->last_exit = ft_itoa(exit_status);
	return (true);
}
