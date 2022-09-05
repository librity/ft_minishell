/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_scramble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 12:22:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static uint32_t	resolve_f(uint32_t _[4], uint32_t i)
{
	if (i <= 15)
		return (_[_D] ^ (_[_B] & (_[_C] ^ _[_D])));
	if (i <= 31)
		return (_[_C] ^ (_[_D] & (_[_B] ^ _[_C])));
	if (i <= 47)
		return (_[_B] ^ _[_C] ^ _[_D]);
	return (_[_C] ^ (_[_B] | (~_[_D])));
}

static uint32_t	resolve_g(uint32_t i)
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

	f = resolve_f(_, i);
	g = resolve_g(i);
	f = f + _[_A] + md5_sines()[i] + words[g];
	_[_A] = _[_D];
	_[_D] = _[_C];
	_[_C] = _[_B];
	_[_B] = _[_B] + ft_rotate_left_ui32(f, md5_rotations()[i]);
}
