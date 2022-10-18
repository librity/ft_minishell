/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 18:25:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Safely allocates memory and adds it to the lalloc.
 *
 * @param lalloc A linked list with the pointers of all allocated variables.
 * @param size The number of bytes to be allocated.
 * @return void* The address of the allocated memory.
 */
void	*ft_lalloc(t_list **lalloc, size_t size)
{
	void	*pointer;

	pointer = ft_salloc(size);
	ft_add_lalloc(lalloc, pointer);
	return (pointer);
}
