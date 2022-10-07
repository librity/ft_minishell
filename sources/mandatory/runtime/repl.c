/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:00:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/07 16:56:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	repl(void)
{
	char			*input;
	char			**tokens;
	t_parse_list	*plist;

	while (true)
	{
		// input = NULL;
		// tokens = NULL;
		// plist = NULL;
		input = prompt();
		ft_debug("input = %s", input);
		if (input == NULL)
			continue ;
		ft_add_lalloc(lalloc(), input);
		input = expand(input);
		ft_add_lalloc(lalloc(), input);
		tokens = lex(input);
		ft_add_lalloc_strarr(lalloc(), tokens);
		if (!tokens_are_valid(tokens))
		{
			// TODO: Mensagem de erro especifica.
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
