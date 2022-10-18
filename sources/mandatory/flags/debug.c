/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:56:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 20:07:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_debug_flag(void)
{
	char	*flag;

	if (argc() < 2)
		return ;
	if (argv() == NULL)
		return ;
	flag = argv()[1];
	if (flag == NULL)
		return ;
	if (!ft_streq(flag, DEBUG_FLAG) && !ft_streq(flag, DEBUG_FLAG_LONG))
		return ;
	enable_debug();
}
