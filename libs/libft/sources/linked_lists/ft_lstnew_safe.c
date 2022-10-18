/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates an isolated and allocated node of a linked list or dies trying.
 *
 * @param content The content of the new node.
 * @return t_list* The new node.
 */
t_list	*ft_lstnew_safe(void *content)
{
	t_list	*list;

	list = (t_list *)ft_salloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}
