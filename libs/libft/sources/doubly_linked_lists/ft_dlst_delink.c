/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_delink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/31 17:46:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Links the node's previous and next nodes to each other,
 * separating it from the doubly linked list.
 *
 * @param node The node to be delinked.
 */
void	ft_dlst_delink(t_dlist *node)
{
	t_dlist	*previous;
	t_dlist	*next;

	previous = node->prev;
	next = node->next;
	if (previous != NULL)
		previous->next = next;
	if (next != NULL)
		next->prev = previous;
}
