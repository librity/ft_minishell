/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:22:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:30:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Runs the del function on the contents of a node of
 * a doubly linked list, then frees it.
 *
 * @param node The first node of the doubly linked list.
 * @param del The callback that runs on every node.
 */
void	ft_dlstdelone(t_dlist *node, void (*del)(void *))
{
	if (node == NULL)
		return ;
	del(node->content);
	free(node);
}
