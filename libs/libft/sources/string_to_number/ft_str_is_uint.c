/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:09:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static bool	is_valid_string(char *str)
{
	if (ft_strlen(str) > UINT_STRING_MAX_LENGTH)
		return (false);
	if (ft_is_plus_or_minus(*str))
		str++;
	if (!ft_isdigit(*str))
		return (false);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (false);
	return (true);
}

/**
 * @brief Returns true if the string represents a valid unsigned int.
 *
 * @param str The number string to be checked.
 * @return true If number string is a valid unsigned int.
 * @return false If number string is not a valid unsigned int.
 */
bool	ft_str_is_uint(char *str)
{
	long	number;

	if (!is_valid_string(str))
		return (false);
	number = ft_atol(str);
	if (number > UINT_MAX)
		return (false);
	if (number < 0)
		return (false);
	return (true);
}
