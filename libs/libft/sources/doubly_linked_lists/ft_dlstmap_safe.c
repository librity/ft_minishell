/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:02:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:31:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates a new doubly linked list
 * and runs f on each content or dies trying.
 *
 * @param node The first node of the doubly linked list.
 * @param f The callback that runs on each node of the list.
 * @return t_dlist* The first node of the mapped list.
 */
t_dlist	*ft_dlstmap_safe(t_dlist *node, void *(*f)(void *))
{
	t_dlist	*list_map;

	if (node == NULL)
		return (NULL);
	list_map = ft_dlstnew_safe(f(node->content));
	list_map->next = ft_dlstmap_safe(node->next, f);
	if (list_map->next != NULL)
		list_map->next->prev = list_map;
	return (list_map);
}
