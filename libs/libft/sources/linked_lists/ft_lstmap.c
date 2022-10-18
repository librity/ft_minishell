/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:02:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 21:53:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates a new linked list and runs f on each content.
 * If it fails in creating a node it clears the list with del.
 *
 * @param node The first node of the linked list.
 * @param f The callback that runs on each node of the list.
 * @param del The callback that runs on every node.
 * @return t_list* The first node of the mapped list or NULL.
 */
t_list	*ft_lstmap(t_list *node, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_map;

	if (node == NULL)
		return (NULL);
	list_map = ft_lstnew(f(node->content));
	if (list_map == NULL)
	{
		ft_lstclear(&list_map, del);
		return (NULL);
	}
	list_map->next = ft_lstmap(node->next, f, del);
	return (list_map);
}
