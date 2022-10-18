/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_pluck_first.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Extracts and returns the trimmed first node of a doubly linked list.
 *
 * @param list The doubly linked list.
 * @return t_dlist* The trimmed node or NULL.
 */
t_dlist	*ft_dlst_pluck_first(t_dlist **list)
{
	t_dlist	*first;
	t_dlist	*second;

	if (list == NULL || *list == NULL)
		return (NULL);
	first = *list;
	second = first->next;
	ft_dlst_trim(first);
	ft_dlst_trim_prev(second);
	*list = second;
	return (first);
}
