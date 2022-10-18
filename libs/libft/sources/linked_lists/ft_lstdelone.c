/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:22:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 21:51:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Runs the del function on the contents of a node of a linked list,
 * then frees it.
 *
 * @param node The first node of the linked list.
 * @param del The callback that runs on every node.
 */
void	ft_lstdelone(t_list *node, void (*del)(void *))
{
	if (node == NULL)
		return ;
	del(node->content);
	free(node);
}
