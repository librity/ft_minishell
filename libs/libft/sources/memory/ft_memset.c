/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:41:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Set the memory from s to s + n to an unsigned char c.
 *
 * @param s The initial memory address.
 * @param c The char to write on each byte.
 * @param n The number of bytes to write.
 * @return void* The initial memory address (s).
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointerator;
	unsigned char	casted_char;

	pointerator = s;
	casted_char = (unsigned char)c;
	while (n--)
	{
		*pointerator = casted_char;
		pointerator++;
	}
	return (s);
}
