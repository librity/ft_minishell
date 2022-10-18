/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:03:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Gets the zero-indexed node of a doubly linked list.
 * If list is uninitialized or empty returns, returns NULL.
 * If index is out of bounds, returns NULL.
 *
 * @param list The doubly linked list.
 * @param index The index of the node.
 * @return t_dlist* The node or NULL.
 */
t_dlist	*ft_dlst_get(t_dlist **list, int index)
{
	t_dlist	*node;

	if (list == NULL || *list == NULL)
		return (NULL);
	if (ft_dlst_index_out_of_bounds(list, index))
		return (NULL);
	node = *list;
	while (index && node != NULL)
	{
		node = node->next;
		index--;
	}
	return (node);
}
