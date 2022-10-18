/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:02:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 21:51:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	*return_unchanged(void *content)
{
	return (content);
}

/**
 * @brief Creates a copy of the linked list.
 * If it fails in creating any node it clears the list with del.
 *
 * @param node The first node of the linked list.
 * @param del The callback that runs on every node.
 * @return t_dlist* The first node of the cloned list.
 */
t_list	*ft_lstdup(t_list *node, void (*del)(void *))
{
	return (ft_lstmap(node, return_unchanged, del));
}
