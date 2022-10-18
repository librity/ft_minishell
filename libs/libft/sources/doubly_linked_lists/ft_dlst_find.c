/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/31 17:31:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Lienarly searches the linked list for the node
 * and returns it if it finds it.
 *
 * @param list The doubly linked list.
 * @param node The node to be searched.
 * @return t_dlist* The node or NULL.
 */
t_dlist	*ft_dlst_find(t_dlist **list, t_dlist *node)
{
	t_dlist	*_list;

	_list = *list;
	while (_list != NULL)
	{
		if (_list == node)
			return (node);
		_list = _list->next;
	}
	return (NULL);
}
