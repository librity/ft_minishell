/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_get_safe.c                                 :+:      :+:    :+:   */
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
 * If list is uninitialized or empty returns,
 * terminates the program with an error.
 * If index is out of bounds, terminates the program with an error.
 *
 * @param list The doubly linked list.
 * @param index The index of the node.
 * @return t_dlist* The node.
 */
t_dlist	*ft_dlst_get_safe(t_dlist **list, int index)
{
	if (list == NULL || *list == NULL)
		ft_die(DLIST_GET_SAFE_LIST_ERR);
	if (ft_dlst_index_out_of_bounds(list, index))
		ft_die(DLIST_GET_SAFE_INDEX_ERR);
	return (ft_dlst_get(list, index));
}
