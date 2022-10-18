/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 15:36:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	has_backslash(char *token)
{
	while (token != NULL && *token != '\0')
	{
		if (*token == '\\')
			return (true);
		token = skip_quotes(token);
		if (token != NULL)
			token++;
	}
	return (false);
}

bool	tokens_have_backslash(char **tokens)
{
	while (*tokens != NULL)
	{
		if (has_backslash(*tokens))
		{
			print_syntax_error(*tokens);
			return (true);
		}
		tokens++;
	}
	return (false);
}
