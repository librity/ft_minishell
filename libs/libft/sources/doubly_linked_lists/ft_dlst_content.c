/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 23:24:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Returns node's content.
 *
 * @param node The node to be dereferenced.
 * @return void* The node's content or NULL.
 */
void	*ft_dlst_content(t_dlist *node)
{
	if (node == NULL)
		return (NULL);
	if (node->content == NULL)
		return (NULL);
	return (node->content);
}
