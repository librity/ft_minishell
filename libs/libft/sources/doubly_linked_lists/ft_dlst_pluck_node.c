/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_pluck_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/31 17:48:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Extracts the zero-indexed node of a doubly linked list.
 * If list is uninitialized or empty returns, returns NULL.
 * If the node is not in the list or NULL, returns NULL.
 *
 * @param list The doubly linked list.
 * @param target The node to be plucked.
 * @return t_dlist* The node or NULL.
 */
t_dlist	*ft_dlst_pluck_node(t_dlist **list, t_dlist *target)
{
	if (list == NULL || *list == NULL)
		return (NULL);
	if (target == NULL)
		return (NULL);
	if (!ft_dlst_node_in_list(list, target))
		return (NULL);
	if (*list == target)
		return (ft_dlst_pluck_first(list));
	ft_dlst_delink(target);
	ft_dlst_trim(target);
	return (target);
}
