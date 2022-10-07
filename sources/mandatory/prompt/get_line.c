/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:53:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/07 16:54:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*build_ps1(void)
{
	char	path[PATH_MAX];
	char	*ps1;

	getcwd(path, PATH_MAX);
	ps1 = ft_strjoin(getenv("USER"), ":");
	ps1 = ft_strjoin_free(ps1, path);
	ps1 = ft_strjoin_free(ps1, "$ ");
	return (ps1);
}

static char	*read_prompt(void)
{
	char	*line;
	char	*ps1;

	ps1 = build_ps1();
	line = readline(ps1);
	free(ps1);
	return (line);
}

char	*prompt(void)
{
	char	*cmd_line;

	cmd_line = read_prompt();
	// add_history(cmd_line);
	return (cmd_line);
}
