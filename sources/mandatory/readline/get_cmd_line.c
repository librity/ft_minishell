/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:26:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/04 00:26:52 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_cmd_line(char	*tmp)
{
	set_line_cmd(ft_strdup(""));
	while (line_cmd() != NULL && !*line_cmd())
	{
		free(line_cmd());
		printf(GB "%s " WB "in ", getenv("USER"));
		set_line_cmd(readline(tmp));
		if (ft_streq(line_cmd(), "exit"))
			exit(0);
	}
	return (line_cmd());
}
