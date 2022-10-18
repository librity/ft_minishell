/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_left_ui32.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:04:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/25 11:49:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Rotates an unsigned 32-bit word to the left.
 *
 * @param word The word to be rotated.
 * @param rotations The number of rotations.
 * @return int The rotated word.
 */
u_int32_t	ft_rotate_left_ui32(u_int32_t word, u_int32_t rotations)
{
	const int	total_bits = 32;

	return (
		(word << rotations)
		| (word >> (total_bits - rotations))
	);
}
