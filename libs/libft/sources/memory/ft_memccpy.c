/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Copies up to to n bytes from src to dest, stopping at c if it finds it.
 * Not overlap safe.
 *
 * @param dest The destination addess.
 * @param src The source address.
 * @param c The char where the copying stops (useful for copying C-strings).
 * @param n The number of bytes to zero out.
 * @return void* The address after the stop or NULL.
 */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*source_cast;
	unsigned char	*destination_cast;

	if (dest == NULL && src == NULL)
		return (NULL);
	source_cast = (unsigned char *)src;
	destination_cast = (unsigned char *)dest;
	while (n--)
	{
		*destination_cast = *source_cast;
		if (*source_cast == (unsigned char)c)
			return (++destination_cast);
		destination_cast++;
		source_cast++;
	}
	return (NULL);
}
