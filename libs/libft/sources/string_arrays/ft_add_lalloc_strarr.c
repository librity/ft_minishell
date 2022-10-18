/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lalloc_strarr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 16:10:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Add the allocated pointer array and all of its addresses to the lalloc.
 *
 * @param lalloc A linked list with the pointers of all allocated variables.
 * @param allocated_strarr An arbitrary, NULL-terminated C-string array.
 */
void	ft_add_lalloc_strarr(t_list **lalloc, char **allocated_strarr)
{
	ft_add_lalloc_array(lalloc, (void **)allocated_strarr);
}
