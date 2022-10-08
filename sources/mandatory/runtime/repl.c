/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:00:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/08 14:54:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/**
 * TODO: Mensagem de erro de sintaxe especifica.
 */
int	repl(void)
{
	char			*line;
	char			**tokens;
	t_parse_list	*plist;

	while (true)
	{
		line = prompt();
		if (line == NULL)
			quit();
		line = expand(line);
		tokens = lex(line);
		if (!tokens_are_valid(tokens))
		{
			print_error("SYNTAX ERROR!");
			free_lalloc();
			continue ;
		}
		trim_tokens(tokens);
		plist = parse(tokens);
		execute(plist);
		free_lalloc();
	}
	return (0);
}
