/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 23:21:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Returns the next node.
 *
 * @param node The node to be skipped.
 * @return t_dlist* The next node or NULL.
 */
t_dlist	*ft_dlst_next(t_dlist *node)
{
	if (node == NULL)
		return (NULL);
	if (node->next == NULL)
		return (NULL);
	return (node->next);
}
