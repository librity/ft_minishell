/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_right_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:04:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/25 11:50:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Rotates an int to the right.
 *
 * @param word The word to be rotated.
 * @param rotations The number of rotations.
 * @return int The rotated word.
 */
int	ft_rotate_right_i(int word, int rotations)
{
	const int	total_bits = sizeof(int) * 8;

	return (
		(word >> rotations)
		| (word << (total_bits - rotations))
	);
}
