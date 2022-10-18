/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:00:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/18 06:52:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*line_or_quit(void)
{
	char	*line;

	line = prompt();
	if (line == NULL)
	{
		printf("\n");
		quit();
	}
	return (line);
}

static void	trim_parse_exec(char **tokens)
{
	t_parse_list	*plist;

	trim(tokens);
	plist = parse(tokens);
	execute(plist);
	free_lalloc();
}

void	repl(void)
{
	char	*line;
	char	**tokens;

	while (true)
	{
		set_interactive_shell_hooks();
		line = line_or_quit();
		if (ft_streq(line, EMPTY_STR))
		{
			free_lalloc();
			continue ;
		}
		line = expand(line);
		tokens = lex(line);
		if (!line_is_valid(line) || !tokens_are_valid(tokens))
		{
			free_lalloc();
			continue ;
		}
		trim_parse_exec(tokens);
	}
}
