/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:53:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/01 17:50:22 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*pwd(void)
{
	char	path[MAX_PATH];

	return (ft_strjoin(getcwd(path, MAX_PATH), "$ "));
}

bool	verific_asp_line_cmd(char	*line)
{
	int	single;
	int	doub;

	single = 0;
	doub = 0;
	while(*line++)
	{
		if (*line == SINGLE_QUOTE && doub % 2 == 0)
			single++;
		if (*line == DOUBLE_QUOTE && single % 2 == 0)
			doub++;
	}
	if (single % 2 == 1 || doub % 2 == 1)
		return (false); //função pra lipar e sair;
	return (true);
}

char	*get_line_cmd(char	*tmp)
{
	set_line_cmd(ft_strdup(""));
	while (!*line_cmd())
	{
		free(line_cmd());
		printf(GB "%s " WB "in ", getenv("USER"));
		set_line_cmd(readline(tmp));
		if (ft_streq(line_cmd(), "exit"))
			exit(0);
	}
	return (line_cmd());
}

void	get_tokens(void)
{
	char	*tmp;

	tmp = pwd();
	get_line_cmd(tmp);
	verific_asp_line_cmd(line_cmd());
	add_history(line_cmd());
	c()->tokens = lex();
	free(tmp);
}

