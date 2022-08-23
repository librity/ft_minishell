/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 19:44:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	strbuff_insert(char *buffer, char insert_me)
{
	char	*reverser;

	reverser = buffer + ft_strlen(buffer);
	while (reverser + 1 > buffer)
	{
		*(reverser + 1) = *reverser;
		reverser--;
	}
	*buffer = insert_me;
}

void	strbuff_insert_before(char *buffer, char insert_me)
{
	strbuff_insert(buffer, insert_me);
}

void	strbuff_insert_after(char *buffer, char insert_me)
{
	strbuff_insert(buffer + 1, insert_me);
}

void	strbuff_insert_around(char *buffer, char insert_me)
{
	strbuff_insert_after(buffer, insert_me);
	strbuff_insert_before(buffer, insert_me);
}

void	strbuff_insert_around_2(char *buffer, char insert_me)
{
	strbuff_insert_after(buffer + 1, insert_me);
	strbuff_insert_before(buffer, insert_me);
}
