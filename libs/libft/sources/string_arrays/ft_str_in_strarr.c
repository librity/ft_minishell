/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_strarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:50:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Returns true if needle is in NULL-terminated haystack.
 *
 * @param haystack The NULL-terminated C-string array.
 * @param needle The C-string you're looking for.
 * @return true If the string is in the array.
 * @return false If the string is not in the array.
 */
bool	ft_str_in_strarr(char **haystack, char *needle)
{
	char	*result;

	result = ft_find_in_strarr(haystack, needle);
	if (result == NULL)
		return (false);
	return (true);
}
