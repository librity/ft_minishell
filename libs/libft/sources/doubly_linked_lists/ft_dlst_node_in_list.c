/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_node_in_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/31 17:47:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Lienarly searches the linked list for the node
 * and returns true if it finds it.
 *
 * @param list The doubly linked list.
 * @param node The node to be searched.
 * @return true The node is in the list.
 * @return false The node is not in the list.
 */
bool	ft_dlst_node_in_list(t_dlist **list, t_dlist *node)
{
	t_dlist	*node_in_list;

	node_in_list = ft_dlst_find(list, node);
	if (node_in_list == NULL)
		return (false);
	return (true);
}
