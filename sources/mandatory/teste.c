/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:39:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 22:05:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_user_line(void)
{
	// char	*line;

	// line = readline(">");
	// return (line);
	char	*buffer;
	int		size;

	buffer = (char *)ft_salloc(FT_ARG_MAX);
	size = read(STDIN_FILENO, buffer, FT_ARG_MAX);
	buffer[size - 1] = '\0';
	return(buffer);
}
