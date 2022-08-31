/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:41:55 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 17:40:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define DEBUG_MESSAGE "Lexed string \"%s\" into tokens:"

char	**lex(void)
{
	char	**tokens;

	tokens = tokenize(line_cmd());
	if (debug())
	{
		ft_debug(DEBUG_MESSAGE, line_cmd());
		ft_put_strarr(tokens);
	}
	return (tokens);
}
