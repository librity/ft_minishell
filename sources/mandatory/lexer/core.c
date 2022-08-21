/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:41:55 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/21 00:51:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define DEBUG_MESSAGE "Lexed string \"%s\" into tokens:"

char	**lex(char *input)
{
	char	**tokens;

	tokens = tokenize(input);
	if (debug())
	{
		ft_debug(DEBUG_MESSAGE, input);
		ft_put_strarr(tokens);
	}
	return (tokens);
}
