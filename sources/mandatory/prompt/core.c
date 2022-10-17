/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:53:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/17 15:57:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	build_path(char *path)
{
	char	*home;
	int		length;

	getcwd(path, PATH_MAX);
	home = getenv(HOME_KEY);
	if (home == NULL)
		return ;
	if (!ft_starts_with(path, home))
		return ;
	length = ft_strlen(home) - 1;
	while (length--)
		strbuff_cut(path);
	path[0] = '~';
}

static char	*build_ps1(void)
{
	char	path[PATH_MAX];
	char	*ps1;
	char	*username;

	build_path(path);
	username = getenv(USERNAME_KEY);
	ps1 = ft_strdup(CB);
	if (username != NULL)
		ps1 = ft_strjoin_free(ps1, username);
	ps1 = ft_strjoin_free(ps1, WB ":" YB);
	ps1 = ft_strjoin_free(ps1, path);
	ps1 = ft_strjoin_free(ps1, "$ " RC);
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
	char	*line;

	line = read_prompt();
	ft_bdebug(debug(), "prompt = \"%s\"", line);
	if (line == NULL)
		return (line);
	ft_add_lalloc(lalloc(), line);
	increase_line_count();
	if (!ft_streq(line, EMPTY_STR))
		add_history(line);
	return (line);
}
