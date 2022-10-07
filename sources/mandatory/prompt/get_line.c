/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:53:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/07 15:49:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*pwd(void)
{
	char	path[PATH_MAX];

	return (ft_strjoin(getcwd(path, PATH_MAX), "$ "));
}

static char	*get_cmd_line(char *tmp)
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

char	*prompt(void)
{
	char	*path;
	char	*cmd_line;

	path = pwd();
	cmd_line = get_cmd_line(path);
	free(path);
	add_history(cmd_line);
	return (cmd_line);
}
