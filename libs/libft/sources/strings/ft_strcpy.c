/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:32:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Copies a C-string to an arbitrary location.
 *
 * @param dest The destination address.
 * @param src The source address.
 * @return char* The destination address.
 */
char	*ft_strcpy(char *dest, char *src)
{
	char	*initial_destination;

	initial_destination = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (initial_destination);
}
