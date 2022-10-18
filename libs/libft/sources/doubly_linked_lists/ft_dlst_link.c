/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/31 15:33:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Inserts the node between previous and next,
 * inserting it into the doubly linked list.
 *
 * @param previous The previous node to link to.
 * @param node The node to be linked.
 * @param next The next node to link to.
 */
void	ft_dlst_link(t_dlist *previous, t_dlist *node, t_dlist *next)
{
	node->prev = previous;
	node->next = next;
	if (previous != NULL)
		previous->next = node;
	if (next != NULL)
		next->prev = node;
}
