/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 15:59:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Safely allocates memory and adds it to the lalloc.
 *
 * @param lalloc A linked list with the pointers of all allocated variables.
 * @param nmemb Number of elements.
 * @param size Byte size of each element.
 * @return void* The address of the allocated memory.
 */
void	*ft_clalloc(t_list **lalloc, size_t nmemb, size_t size)
{
	void	*pointer;

	pointer = ft_scalloc(nmemb, size);
	ft_add_lalloc(lalloc, pointer);
	return (pointer);
}
