/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_scramble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/31 19:30:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

typedef enum e_chuck_digest_ints
{
	_A = 0,
	_B = 1,
	_C = 2,
	_D = 3,
	_FIRST = _A,
	_LAST = _D
}			t_chuck_digest_ints;

static uint32_t	calculate_f(uint32_t _[4], uint32_t i)
{
	if (i <= 15)
		return (_[_D] ^ (_[_B] & (_[_C] ^ _[_D])));
	if (i <= 31)
		return (_[_C] ^ (_[_D] & (_[_B] ^ _[_C])));
	if (i <= 47)
		return (_[_B] ^ _[_C] ^ _[_D]);
	return (_[_C] ^ (_[_B] | (~_[_D])));
}

static uint32_t	calculate_g(uint32_t i)
{
	if (i <= 15)
		return (i);
	if (i <= 31)
		return ((5 * i + 1) % 16);
	if (i <= 47)
		return ((3 * i + 5) % 16);
	return ((7 * i) % 16);
}

void	md5_scramble_chunk_digest(uint32_t i, uint32_t words[16], uint32_t _[4])
{
	uint32_t	f;
	uint32_t	g;

	f = calculate_f(_, i);
	g = calculate_g(i);
	f = f + _[_A] + md5_sines()[i] + words[g];
	_[_A] = _[_D];
	_[_D] = _[_C];
	_[_C] = _[_B];
	_[_B] = _[_B] + ft_rotate_left_ui32(f, md5_rotations()[i]);
}
