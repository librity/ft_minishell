/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:48:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 21:52:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Return last node of a linked list.
 *
 * @param node The first node of the linked list.
 * @return t_list* The last node of the list or NULL.
 */
t_list	*ft_lstlast(t_list *node)
{
	if (node == NULL)
		return (NULL);
	if (node->next == NULL)
		return (node);
	return (ft_lstlast(node->next));
}
