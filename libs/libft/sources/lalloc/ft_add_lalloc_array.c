/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lalloc_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Add the allocated pointer array and all of its addresses to the lalloc.
 *
 * @param lalloc A linked list with the pointers of all allocated variables.
 * @param allocated_array An arbitrary, NULL-terminated array.
 */
void	ft_add_lalloc_array(t_list **lalloc, void **allocated_array)
{
	if (allocated_array == NULL)
		return ;
	ft_add_lalloc(lalloc, allocated_array);
	while (*allocated_array != NULL)
	{
		ft_add_lalloc(lalloc, *allocated_array);
		allocated_array++;
	}
}
