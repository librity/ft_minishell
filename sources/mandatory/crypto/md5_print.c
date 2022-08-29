/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 12:57:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_md5(uint32_t *digest)
{
	int					word;
	int					byte;
	t_byte_word_ui32	bw;

	word = 0;
	while (word < 4)
	{
		bw.word = digest[word];
		byte = 0;
		while (byte < 4)
		{
			ft_printf("%02x", bw.bytes[byte]);
			byte++;
		}
		word++;
	}
}

void	inspect_md5(char *message, uint32_t *digest)
{
	ft_printf("\"%s\" => ", message);
	print_md5(digest);
	ft_printf("\n");
}
