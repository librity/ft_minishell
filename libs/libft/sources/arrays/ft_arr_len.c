/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/25 12:29:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Counts how many pointers a NULL-terminated array has excluding NULL.
 *
 * @param array The array to be counted.
 * @return size_t The number of pointers.
 */
size_t	ft_arr_len(void **array)
{
	size_t	length;

	if (array == NULL)
		return (0);
	length = 0;
	while (array[length])
		length++;
	return (length);
}
