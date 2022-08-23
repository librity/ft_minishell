/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 19:11:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	insert_in_buffer(char *buffer, char c)
{
	char	*reverser;

	reverser = buffer + ft_strlen(buffer);
	while (reverser + 1 > buffer)
	{
		*(reverser + 1) = *reverser;
		reverser--;
	}
	*buffer = c;
}

void	insert_char_before(char *buffer, char c)
{
	insert_in_buffer(buffer, c);
}

void	insert_char_after(char *buffer, char c)
{
	insert_in_buffer(buffer + 1, c);
}

void	insert_char_around(char *buffer, char c)
{
	insert_char_after(buffer, c);
	insert_char_before(buffer, c);
}
