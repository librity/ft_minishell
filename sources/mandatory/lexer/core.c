/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:41:55 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/07 21:06:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	debug_tokens(char *input, char **tokens)
{
	if (!debug())
		return ;
	ft_debug(TOKENS_DEBUG_MESSAGE, input);
	ft_put_strarr(tokens);
}

char	**lex(char *input)
{
	char	**tokens;

	tokens = tokenize(input);
	ft_add_lalloc_strarr(lalloc(), tokens);
	debug_tokens(input, tokens);
	return (tokens);
}
