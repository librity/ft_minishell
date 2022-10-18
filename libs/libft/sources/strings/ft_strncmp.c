/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:56:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Compares strings s1 and s2 char-wise, returning the difference.
 *
 * @param s1 The first C-string.
 * @param s2 The second C-string.
 * @param n The number of bytes to compare.
 * @return int The Difference between the chars or zero.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	current;

	current = 0;
	while ((s1[current] || s2[current]) && current < n)
	{
		if (s1[current] != s2[current])
			return ((unsigned char)s1[current] - (unsigned char)s2[current]);
		current++;
	}
	return (0);
}
