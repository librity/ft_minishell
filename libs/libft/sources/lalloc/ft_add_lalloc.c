/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Initializes lalloc (if necessary)
 * and adds the allocated address to the list.
 *
 * @param lalloc A linked list with the pointers of all allocated variables.
 * @param allocated_address An allocated memory address.
 */
void	ft_add_lalloc(t_list **lalloc, void *allocated_address)
{
	ft_lst_cadd_front(lalloc, allocated_address);
}
