/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 15:59:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Allocates (nmemb * size) bytes of memory memory
 * and sets them all to zero.
 * If allocation fails it terminates the program with an error.
 *
 * @param nmemb Number of elements.
 * @param size Byte size of each element.
 * @return void* The address of the allocated memory.
 */
void	*ft_scalloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*allocated;

	total_size = nmemb * size;
	allocated = ft_salloc(total_size);
	ft_bzero(allocated, total_size);
	return (allocated);
}
