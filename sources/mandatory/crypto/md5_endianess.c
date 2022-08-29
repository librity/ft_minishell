/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_endianess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 15:43:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	md5_switch_endianess(uint32_t *digest)
{
	int	word;

	word = 0;
	while (word < 4)
	{
		digest[word] = ft_switch_byte_endianess_ui32(digest[word]);
		word++;
	}
}

uint32_t	*md5_little_endian(void *message, size_t msg_length)
{
	return (md5(message, msg_length));
}

uint32_t	*md5_big_endian(void *message, size_t msg_length)
{
	uint32_t	*digest;

	digest = md5(message, msg_length);
	md5_switch_endianess(digest);
	return (digest);
}
