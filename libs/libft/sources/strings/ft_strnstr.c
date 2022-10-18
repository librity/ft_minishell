/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Finds the first occurence of needle in haystack up to length.
 *
 * @param haystack The C-string to be searched.
 * @param needle The C-string to be search.
 * @param len The number of bytes to search.
 * @return char* The first occurence of needle in haystack or NULL.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_start;
	char	*needle_pointerator;
	char	*possible_match;

	haystack_start = (char *)haystack;
	if (*needle == '\0')
		return (haystack_start);
	while (*haystack)
	{
		needle_pointerator = (char *)needle;
		possible_match = (char *)haystack;
		while (*needle_pointerator
			&& *haystack == *needle_pointerator
			&& (unsigned long)(haystack - haystack_start) < len)
		{
			needle_pointerator++;
			haystack++;
		}
		if (*needle_pointerator == '\0')
			return (possible_match);
		haystack = possible_match + 1;
	}
	return (NULL);
}
