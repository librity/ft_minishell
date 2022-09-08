/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:51:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 17:06:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_specialchar(char *str)
{
	char	*specialchar;

	specialchar = SPECIALCHARS;
	while (*specialchar != '\0')
	{
		if (ft_has_char(str, *specialchar))
			return (true);
		specialchar++;
	}
	return (false);
}

bool	is_specialchar(char c)
{
	return (ft_has_char(SPECIALCHARS, c));
}
