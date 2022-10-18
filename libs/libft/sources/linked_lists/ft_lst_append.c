/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:57:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates a node and appends it to the end of
 * an initialized linked list.
 *
 * @param list The linked list.
 * @param content The content of the new node.
 */
void	ft_lst_append(t_list **list, void *content)
{
	t_list	*new;

	if (list == NULL || *list == NULL)
		return ;
	new = ft_lstnew_safe(content);
	ft_lstadd_back(list, new);
}
