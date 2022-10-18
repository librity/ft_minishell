/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:41:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Scans first n bytes after s for c. Returns c's position if it finds it.
 * Returns NULL otherwise.
 *
 * @param s The initial address.
 * @param c The char being searched.
 * @param n The number of bytes searched.
 * @return void* The address where it found c or NULL.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string_cast;

	string_cast = (unsigned char *)s;
	while (n--)
	{
		if (*string_cast == (unsigned char)c)
			return (string_cast);
		string_cast++;
	}
	return (NULL);
}
