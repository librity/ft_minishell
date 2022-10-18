/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_cutn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 23:18:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Cuts up to n pointers of a NULL-terminated C-string array.
 *
 * @param cut_me The pointer to be cut.
 * @param cut_me The number of pointers to cut.
 */
void	ft_strarr_cutn(char **cut_me, int n)
{
	if (cut_me == NULL)
		return ;
	if (n <= 0)
		return ;
	while (*cut_me != NULL && n > 0)
	{
		ft_strarr_cut(cut_me);
		n--;
	}
}
