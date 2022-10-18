/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief
 * Creates a new node wih the content.
 * If the linked list is initialized, appends the node to the list.
 * If uninitialized, sets the node as first on the list.
 *
 * @param list The linked list.
 * @param content The content of the new node.
 */
void	ft_lst_cadd_front(t_list **list, void *content)
{
	if (list == NULL)
		return ;
	if (*list == NULL)
		return (ft_lst_init_safe(list, content));
	ft_lst_append(list, content);
}
