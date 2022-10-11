/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 12:56:47 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*insert_double_quote_delimiters(char *line)
{
	line++;
	while (*line != '\0' && *line != DOUBLE_QUOTE)
	{
		if (at_dollar(line))
			insert_delimiter(line);
		line++;
	}
	return (line);
}

static char	*skip_or_delimit(char *line)
{
	if (at_single_quote(line))
		return (skip_single_quotes(line));
	if (at_dollar(line))
		return (insert_delimiter(line));
	if (at_double_quote(line))
		return (insert_double_quote_delimiters(line));
	return (line);
}

static void	insert_delimiters(char *line)
{
	while (line != NULL && *line != '\0')
	{
		line = skip_or_delimit(line);
		if (line != NULL)
			line++;
	}
}

char	**isolate_variables(char *input)
{
	static char	buffer[FT_ARG_MAX];
	char		**vars;

	ft_strcpy(buffer, input);
	insert_delimiters(buffer);
	vars = ft_split(buffer, DELIMITER);
	return (vars);
}
