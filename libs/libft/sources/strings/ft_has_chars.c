/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 17:17:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Checks if the needle contains any characters of haystack.
 *
 * @param haystack The C-string to check with.
 * @param needle The C-string to be checked.
 * @return true Needle contains a character of haystack.
 * @return false Needle does not contain a character of haystack.
 */
bool	ft_has_chars(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		if (ft_has_char(needle, *haystack))
			return (true);
		haystack++;
	}
	return (false);
}
