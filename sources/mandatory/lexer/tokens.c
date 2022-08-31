/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:36:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 11:35:13 by wjuneo-f         ###   ########.fr       */
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

static void	insert_trivial_delimiters(char *line)
{
	while (line != NULL && *line != '\0')
	{
		line = skip_or_delimit(line);
		if (line != NULL)
			line++;
	}
}

// char	**tokenize(char *line, t_data *data)
// {
// 	char	line_buffer[FT_ARG_MAX];
// 	char	**tokens;

// 	ft_strcpy(line_buffer, line);
// 	insert_trivial_delimiters(line_buffer);
// 	data->tokens = ft_split(line_buffer, DELIMITER);
// }

char	**tokenize(char *line)
{
	char	line_buffer[FT_ARG_MAX];
	char	**tokens;

	ft_strcpy(line_buffer, line);
	insert_trivial_delimiters(line_buffer);
	tokens = ft_split(line_buffer, DELIMITER);
	return (tokens);
}
