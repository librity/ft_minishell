/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Compares the first n bytes of s1 with the first n bytes of s2.
 * If any one byte is different, returns *s1 - *s2.
 *
 * @param s1 The first address.
 * @param s2 The second address.
 * @param n The number of bytes to compare.
 * @return int The difference between the chars or zero.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first_cast;
	unsigned char	*second_cast;

	first_cast = (unsigned char *)s1;
	second_cast = (unsigned char *)s2;
	while (n--)
	{
		if (*first_cast != *second_cast)
			return (*first_cast - *second_cast);
		first_cast++;
		second_cast++;
	}
	return (0);
}
