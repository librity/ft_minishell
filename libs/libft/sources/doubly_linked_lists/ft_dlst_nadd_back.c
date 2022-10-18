/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_nadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:57:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Adds a node to the end of a doubly linked list.
 *
 * @param list The doubly linked list.
 * @param new The node to be added.
 */
void	ft_dlst_nadd_back(t_dlist **list, t_dlist *new)
{
	ft_dlstadd_back(list, new);
}
