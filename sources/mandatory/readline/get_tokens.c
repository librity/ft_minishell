/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:53:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/02 22:58:35 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*pwd(void)
{
	char	path[MAX_PATH];

	return (ft_strjoin(getcwd(path, MAX_PATH), "$ "));
}

char	*get_line_cmd(char	*tmp)
{
	/*
		NOTE: sua função estava dando seg fault quando recebia um parametro null
		coloquei um if temporario la :)
	*/
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
	vf_clone_quote(line_cmd());
	add_history(line_cmd());
	c()->tokens = lex();
	free(tmp);
}

