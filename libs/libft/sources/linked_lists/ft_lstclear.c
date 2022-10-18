/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:12:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Runs the del function on all the contents of a linked list,
 * frees every node and uninitializes the list.
 *
 * @param list The linked list.
 * @param del The callback that runs on every node.
 */
void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*next;

	if (list == NULL)
		return ;
	while (*list != NULL)
	{
		next = (*list)->next;
		ft_lstdelone(*list, del);
		*list = next;
	}
	list = NULL;
}
