/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 15:51:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	md5_pad_message(t_md5 *m)
{
	uint64_t	length_bits;
	uint32_t	i;

	m->chunks = 1 + (m->msg_length + 8) / 64;
	m->padded_message = ft_salloc(64 * m->chunks);
	ft_memcpy(m->padded_message, m->message, m->msg_length);
	m->padded_message[m->msg_length] = ONE_BIT;
	i = m->msg_length + 1;
	while (i < 64 * m->chunks)
	{
		m->padded_message[i] = NULL_BYTE;
		i++;
	}
	length_bits = 8 * m->msg_length % ULLONG_MAX;
	i -= 8;
	ft_memcpy(m->padded_message + i, &length_bits, 8);
}
