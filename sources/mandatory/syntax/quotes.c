/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:34:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 17:47:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_valid_single_quotes(char *line)
{
	while (*line != '\0')
	{
		if (*line == SINGLE_QUOTE)
		{
			line++;
			line = skip_single_quotes(line);
			if (line == NULL)
				return (false);
		}
		line++;
	}
	return (true);
}

bool	has_valid_double_quotes(char *line)
{
	while (*line != '\0')
	{
		if (*line == DOUBLE_QUOTE)
		{
			line++;
			line = skip_double_quotes(line);
			if (line == NULL)
				return (false);
		}
		line++;
	}
	return (true);
}

bool	has_valid_quotes(char *line)
{
	return (
		has_valid_single_quotes(line)
		&& has_valid_double_quotes(line));
}
