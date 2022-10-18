/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pluck_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:05:12 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Extracts and returns the trimmed first node of a linked list.
 *
 * @param list The linked list.
 * @return t_dlist* The trimmed node or NULL.
 */
t_list	*ft_lst_pluck_first(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if (list == NULL || *list == NULL)
		return (NULL);
	first = *list;
	second = first->next;
	ft_lst_trim(first);
	*list = second;
	return (first);
}
