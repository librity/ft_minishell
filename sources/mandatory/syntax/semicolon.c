/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:34:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 15:36:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	has_semicolon(char *token)
{
	while (token != NULL && *token != '\0')
	{
		if (*token == SEMICOLON)
			return (true);
		token = skip_quotes(token);
		if (token != NULL)
			token++;
	}
	return (false);
}

bool	tokens_have_semicolon(char **tokens)
{
	while (*tokens != NULL)
	{
		if (has_semicolon(*tokens))
		{
			print_syntax_error(*tokens);
			return (true);
		}
		tokens++;
	}
	return (false);
}
