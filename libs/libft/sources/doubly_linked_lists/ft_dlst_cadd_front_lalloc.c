/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_cadd_front_lalloc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:43:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates a new node wih the content.
 * If the doubly linked list is initialized, appends the node to the list.
 * If uninitialized, sets the node as first on the list.
 * Then adds node to lalloc.
 *
 * @param lalloc A linked list with the pointers of all allocated variables.
 * @param list The doubly linked list.
 * @param content The content of the new node.
 */
void	ft_dlst_cadd_front_lalloc(t_list **lalloc,
			t_dlist **list, void *content)
{
	t_dlist	*new;

	if (list == NULL)
		return ;
	new = ft_dlstnew_safe(content);
	ft_dlstadd_front(list, new);
	ft_add_lalloc(lalloc, new);
}
