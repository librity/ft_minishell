/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 23:22:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Returns the previous node.
 *
 * @param node The node to be skipped.
 * @return t_dlist* The previous node or NULL.
 */
t_dlist	*ft_dlst_prev(t_dlist *node)
{
	if (node == NULL)
		return (NULL);
	if (node->prev == NULL)
		return (NULL);
	return (node->prev);
}
