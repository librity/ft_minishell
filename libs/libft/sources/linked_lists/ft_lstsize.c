/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:29:43 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 21:53:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Counts the nodes in a linked list.
 *
 * @param node The first node of the linked list.
 * @return int The size of the list.
 */
int	ft_lstsize(t_list *node)
{
	int	list_size;

	if (node == NULL)
		return (0);
	list_size = 1;
	while (node->next != NULL)
	{
		list_size++;
		node = node->next;
	}
	return (list_size);
}
