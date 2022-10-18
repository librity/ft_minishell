/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 18:25:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Allocates (nmemb * size) bytes of memory memory
 * and sets them all to zero.
 *
 * @param nmemb Byte size of each element.
 * @param size Number of elements.
 * @return void* The address of the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*allocated;

	total_size = nmemb * size;
	allocated = malloc(total_size);
	if (allocated == NULL)
		return (NULL);
	ft_bzero(allocated, total_size);
	return (allocated);
}
