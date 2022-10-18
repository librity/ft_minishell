/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 21:51:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Trasverses every node of a linked list and runs f on each content.
 *
 * @param node The first node of the linked list.
 * @param f The callback that runs on each node of the list.
 */
void	ft_lstiter(t_list *node, void (*f)(void *))
{
	if (node == NULL)
		return ;
	f(node->content);
	if (node->next == NULL)
		return ;
	ft_lstiter(node->next, f);
}
