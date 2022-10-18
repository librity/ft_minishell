/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:02:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates a new doubly linked list and runs f on each content.
 * If it fails in creating a node it clears the list with del.
 *
 * @param node The first node of the doubly linked list.
 * @param f The callback that runs on each node of the list.
 * @param del The callback that runs on every node in case of failure.
 * @return t_dlist* The first node of the mapped list.
 */
t_dlist	*ft_dlstmap(t_dlist *node, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*list_map;

	if (node == NULL)
		return (NULL);
	list_map = ft_dlstnew(f(node->content));
	if (list_map == NULL)
	{
		ft_dlstclear(&list_map, del);
		return (NULL);
	}
	list_map->next = ft_dlstmap(node->next, f, del);
	list_map->next->prev = list_map;
	return (list_map);
}
