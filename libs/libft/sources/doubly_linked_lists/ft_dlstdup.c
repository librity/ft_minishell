/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:02:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	*return_unchanged(void *content)
{
	return (content);
}

/**
 * @brief Creates a copy of the doubly linked list.
 * If it fails in creating any node it clears the list with del.
 *
 * @param node The first node of the doubly linked list.
 * @param del The callback that runs on every node in case of failure.
 * @return t_dlist* The first node of the cloned list.
 */
t_dlist	*ft_dlstdup(t_dlist *node, void (*del)(void *))
{
	return (ft_dlstmap(node, return_unchanged, del));
}
