/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_metachar(char *str)
{
	return (ft_has_chars(METACHARS, str));
}

bool	is_metachar(char c)
{
	return (ft_has_char(METACHARS, c));
}

bool	has_specialchar(char *str)
{
	return (ft_has_chars(SPECIALCHARS, str));
}

bool	is_specialchar(char c)
{
	return (ft_has_char(SPECIALCHARS, c));
}
