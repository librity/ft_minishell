/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:00:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/11 15:20:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	trim_parse_exec(char **tokens)
{
	t_parse_list	*plist;

	trim(tokens);
	plist = parse(tokens);
	execute(plist);
	free_lalloc();
}

/**
 * TODO: Mensagem de erro de sintaxe especifica.
 */
void	repl(void)
{
	char	*line;
	char	**tokens;

	while (true)
	{
		set_interactive_shell_hooks();
		line = prompt();
		if (line == NULL)
			quit();
		if (ft_streq(line, EMPTY_STR))
		{
			free_lalloc();
			continue ;
		}
		line = expand(line);
		tokens = lex(line);
		if (!tokens_are_valid(tokens))
		{
			ft_bdebug(debug(), "FOUND SYNTAX ERROR!");
			print_error("SYNTAX ERROR!");
			free_lalloc();
			continue ;
		}
		trim_parse_exec(tokens);
	}
}
