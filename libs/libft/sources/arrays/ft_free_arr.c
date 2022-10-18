/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:50:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 22:34:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Frees a NULL-terminated array.
 *
 * @param free_me The array to be freed.
 */
void	ft_free_arr(void **free_me)
{
	void	**free_me_too;

	if (free_me == NULL)
		return ;
	free_me_too = free_me;
	while (*free_me)
		free(*free_me++);
	free(free_me_too);
}
