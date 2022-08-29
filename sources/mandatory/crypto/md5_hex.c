/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 14:59:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*md5_digest_to_hex(uint32_t *digest)
{
	char				*hex;
	int					word;
	int					offset;

	hex = ft_scalloc(sizeof(char), MD5_HASH_SIZE);
	ft_memset(hex, '0', MD5_HASH_SIZE);
	word = 0;
	while (word < 4)
	{
		offset = word * 8;
		ft_ui_to_buffer_lchex(digest[word], hex + offset);
		word++;
	}
	hex[MD5_HASH_SIZE - 1] = '\0';
	return (hex);
}

char	*md5_hex(char *message)
{
	uint32_t	*digest;
	char		*hex;

	digest = md5_big_endian(message, ft_strlen(message));
	hex = md5_digest_to_hex(digest);
	free(digest);
	return (hex);
}
