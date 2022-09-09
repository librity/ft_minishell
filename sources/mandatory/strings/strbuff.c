/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strbuff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 20:38:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	strbuff_insert(char *buffer, char insert_me)
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

void	strbuff_cut(char *buffer)
{
	while (*buffer != '\0')
	{
		*buffer = *(buffer + 1);
		buffer++;
	}
}
