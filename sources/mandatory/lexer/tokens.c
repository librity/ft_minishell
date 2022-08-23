/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:36:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 19:19:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*skip_or_delimit(char *line)
{
	if (*line == SINGLE_QUOTE)
		return (skip_single_quotes(line));
	if (*line == DOUBLE_QUOTE)
		return (skip_double_quotes(line));
	if (*line == VERTICAL_BAR)
		return (insert_pipe_delimiters(line));
	if (*line == GREATER_THAN)
		return (insert_greater_than_delimiters(line));
	if (*line == LESS_THAN)
		return (insert_less_than_delimiters(line));
	if (*line == SPACE)
		return (insert_delimiter(line));
	return (line);
}

static void	insert_trivial_delimiters(char *line)
{
	while (line != NULL && *line != '\0')
	{
		line = skip_or_delimit(line);
		if (line != NULL)
			line++;
	}
}

char	**tokenize(char *line)
{
	char	line_buffer[FT_ARG_MAX];
	char	**tokens;

	ft_strcpy(line_buffer, line);
	insert_trivial_delimiters(line_buffer);
	tokens = ft_split(line_buffer, DELIMITER);
	return (tokens);
}
