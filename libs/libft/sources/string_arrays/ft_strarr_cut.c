/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_cut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 17:54:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Cuts a pointer of a NULL-terminated C-string array.
 *
 * @param cut_me The pointer to be cut.
 */
void	ft_strarr_cut(char **cut_me)
{
	while (cut_me != NULL && *cut_me != NULL)
	{
		*cut_me = *(cut_me + 1);
		cut_me++;
	}
}
