/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:26:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/07 11:12:16 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_cmd_line(char	*tmp)
{
	char	*line;

	line = (ft_strdup(""));
	while (line != NULL && !*line)
	{
		free(line);
		printf(GB "%s " WB "in ", getenv("USER"));
		line = readline(tmp);
	}
	return (line);
}
