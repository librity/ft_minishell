/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:46:55 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Initialize a length string of lenght 0.
 *
 * @param lstr The length string to be initialized.
 */
void	ft_init_lstr(t_lstr *lstr)
{
	lstr->len = 0;
	lstr->ptr = ft_salloc(lstr->len + 1);
	lstr->ptr[0] = '\0';
}
