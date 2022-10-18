/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_pluck_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Extracts and returns the trimmed last node of a doubly linked list.
 *
 * @param list The doubly linked list.
 * @return t_dlist* The trimmed node or NULL.
 */
t_dlist	*ft_dlst_pluck_last(t_dlist **list)
{
	t_dlist	*last;
	t_dlist	*second_last;

	if (list == NULL || *list == NULL)
		return (NULL);
	last = ft_dlstlast(*list);
	second_last = last->prev;
	ft_dlst_trim_next(second_last);
	if (second_last == NULL)
		*list = NULL;
	ft_dlst_trim(last);
	return (last);
}
