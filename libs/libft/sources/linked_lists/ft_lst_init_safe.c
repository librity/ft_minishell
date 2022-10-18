/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init_safe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Initializes a linked list or dies trying.
 *
 * @param list The linked list.
 * @param content The content of the new node.
 */
void	ft_lst_init_safe(t_list **list, void *content)
{
	if (list == NULL)
		ft_die(LIST_INIT_REFERENCE_ERR);
	if (*list != NULL)
		ft_die(LIST_INIT_NONEMPTY_ERR);
	ft_lst_init(list, content);
}
