/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:41:55 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 16:32:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	debug_tokens(char **tokens)
{
	if (!debug())
		return ;
	ft_yellowb("DEBUG:\t");
	ft_putstr("tokens = { ");
	ft_put_strarr_inline(tokens);
	ft_putstr(", NULL };\n");
}

char	**lex(char *input)
{
	char	**tokens;

	tokens = tokenize(input);
	ft_add_lalloc_strarr(lalloc(), tokens);
	debug_tokens(tokens);
	return (tokens);
}
