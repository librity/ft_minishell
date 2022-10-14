/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:31:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 13:27:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*trimmer_skip_single_quotes(char *line)
{
	return (ft_strchr(line, SINGLE_QUOTE));
}

static char	*trimmer_skip_double_quotes(char *line)
{
	return (ft_strchr(line, DOUBLE_QUOTE));
}

static bool	handled_single_quote(char **token)
{
	if (!at_single_quote(*token))
		return (false);
	strbuff_cut(*token);
	*token = trimmer_skip_single_quotes(*token);
	if (*token != NULL && at_single_quote(*token))
		strbuff_cut(*token);
	return (true);
}

static bool	handled_double_quote(char **token)
{
	if (!at_double_quote(*token))
		return (false);
	strbuff_cut(*token);
	*token = trimmer_skip_double_quotes(*token);
	if (*token != NULL && at_double_quote(*token))
		strbuff_cut(*token);
	return (true);
}

void	trim_token(char *token)
{
	while (token != NULL && *token != '\0')
	{
		if (handled_single_quote(&token))
			continue ;
		if (handled_double_quote(&token))
			continue ;
		if (token != NULL)
			token++;
	}
}
