/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_digest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 16:17:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

typedef enum e_md5_words
{
	_A = 0,
	_B = 1,
	_C = 2,
	_D = 3,
	_FIRST = _A,
	_LAST = _D
}			t_md5_words;

static void	init_chunk(t_md5 *m,
						uint32_t chunk,
						uint32_t words[16],
						uint32_t chunk_digest[4])
{
	uint8_t	*chunk_start;

	chunk_start = m->padded_message + chunk * 64;
	ft_memcpy(words, chunk_start, 64);
	ft_memcpy(chunk_digest, m->digest, MD5_DIGEST_SIZE);
}

static void	add_to_digest(t_md5 *m, uint32_t chunk_digest[4])
{
	uint32_t	i;

	i = 0;
	while (i < 4)
	{
		m->digest[i] += chunk_digest[i];
		i++;
	}
}

static void	calculate_f_and_g(uint32_t i, uint32_t *f, uint32_t *g,
		uint32_t _[4])
{
	if (i <= 15)
	{
		*f = _[_D] ^ (_[_B] & (_[_C] ^ _[_D]));
		*g = i;
		return ;
	}
	if (i <= 31)
	{
		*f = _[_C] ^ (_[_D] & (_[_B] ^ _[_C]));
		*g = (5 * i + 1) % 16;
		return ;
	}
	if (i <= 47)
	{
		*f = _[_B] ^ _[_C] ^ _[_D];
		*g = (3 * i + 5) % 16;
		return ;
	}
	*f = _[_C] ^ (_[_B] | (~_[_D]));
	*g = (7 * i) % 16;
}

static void	scramble(uint32_t i,
						uint32_t words[16],
						uint32_t _[4])
{
	uint32_t	f;
	uint32_t	g;

	calculate_f_and_g(i, &f, &g, _);
	f = f + _[_A] + md5_sines()[i] + words[g];
	_[_A] = _[_D];
	_[_D] = _[_C];
	_[_C] = _[_B];
	_[_B] = _[_B] + ft_rotate_left_ui32(f, md5_rotations()[i]);
}

void	md5_calculate_digest(t_md5 *m)
{
	uint32_t	i;
	uint32_t	chunk;
	uint32_t	words[16];
	uint32_t	_[4];

	chunk = 0;
	while (chunk < m->chunks)
	{
		init_chunk(m, chunk, words, _);
		i = 0;
		while (i < 64)
		{
			scramble(i, words, _);
			i++;
		}
		add_to_digest(m, _);
		chunk++;
	}
}
