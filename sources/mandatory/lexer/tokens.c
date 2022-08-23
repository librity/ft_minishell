/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:36:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 18:01:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	insert_char(char *buffer, char c)
{
	char	*reverser;

	reverser = buffer + ft_strlen(buffer);
	while (reverser + 1 > buffer)
	{
		*(reverser + 1) = *reverser;
		reverser--;
	}
	*buffer = c;
}

static void	insert_char_before(char *buffer, char c)
{
	insert_char(buffer, c);
}

static void	insert_char_after(char *buffer, char c)
{
	insert_char(buffer + 1, c);
}

static void	insert_char_around(char *buffer, char c)
{
	insert_char_after(buffer, c);
	insert_char_before(buffer, c);
}

static char	*skip_squote_enclosed(char *line)
{
	return (ft_strchr(++line, SINGLE_QUOTE));
}

static char	*skip_dquote_enclosed(char *line)
{
	return (ft_strchr(++line, DOUBLE_QUOTE));
}

static char	*insert_pipe_delimiters(char *line)
{
	insert_char_around(line, DELIMITER);
	return (line + 1);
}

static char	*skip_or_delimit(char *line)
{
	if (*line == SINGLE_QUOTE)
		return (skip_squote_enclosed(line));
	if (*line == DOUBLE_QUOTE)
		return (skip_dquote_enclosed(line));
	if (*line == PIPE)
		return (insert_pipe_delimiters(line));
	if (*line == PIPE)
		return (insert_pipe_delimiters(line));
	if (*line == SPACE)
		*line = DELIMITER;
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
