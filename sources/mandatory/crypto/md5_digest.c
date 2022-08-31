/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_digest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/31 19:28:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

static void	digest_chunk(t_md5 *m, uint32_t chunk)
{
	uint32_t	words[16];
	uint32_t	chunk_digest[4];
	uint32_t	i;

	init_chunk(m, chunk, words, chunk_digest);
	i = 0;
	while (i < 64)
	{
		md5_scramble_chunk_digest(i, words, chunk_digest);
		i++;
	}
	add_to_digest(m, chunk_digest);
}

void	md5_calculate_digest(t_md5 *m)
{
	uint32_t	chunk;

	chunk = 0;
	while (chunk < m->chunks)
	{
		digest_chunk(m, chunk);
		chunk++;
	}
}
