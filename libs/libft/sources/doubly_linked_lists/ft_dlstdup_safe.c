/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdup_safe.c                                  :+:      :+:    :+:   */
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
 * @brief Creates a copy of the doubly linked list or dies trying.
 *
 * @param node The first node of the doubly linked list.
 * @return t_dlist* The first node of the cloned list.
 */
t_dlist	*ft_dlstdup_safe(t_dlist *node)
{
	return (ft_dlstmap_safe(node, return_unchanged));
}
