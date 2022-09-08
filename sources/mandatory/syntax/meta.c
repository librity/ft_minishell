/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 17:06:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_metachar(char *str)
{
	char	*metachar;

	metachar = METACHARS;
	while (*metachar != '\0')
	{
		if (ft_has_char(str, *metachar))
			return (true);
		metachar++;
	}
	return (false);
}

bool	is_metachar(char c)
{
	return (ft_has_char(METACHARS, c));
}
