/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:36:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/13 17:07:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*skip_or_delimit(char *line)
{
	if (at_space(line))
		return (insert_delimiter(line));
	if (at_single_quote(line))
		return (skip_single_quotes(line));
	if (at_double_quote(line))
		return (skip_double_quotes(line));
	if (at_append(line) || at_heredoc(line))
		return (insert_around_two(line));
	if (at_pipe(line) || at_truncate(line) || at_read_file(line))
		return (insert_around_one(line));
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

char	**tokenize(char *line)
{
	static char	buffer[FT_ARG_MAX];
	char		**tokens;

	ft_strcpy(buffer, line);
	insert_delimiters(buffer);
	tokens = ft_split(buffer, DELIMITER);
	return (tokens);
}
