/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:36:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/20 23:22:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	subvert_spaces_within_delimiter(char *str, char delimiter)
{
	str = ft_strchr(str, delimiter);
	while (str != NULL && *str != '\0')
	{
		str++;
		while (*str != delimiter && *str != '\0')
		{
			if (*str == SPACE)
				*str = NOT_ASCII;
			str++;
		}
		if (*str == delimiter)
		{
			str++;
			str = ft_strchr(str, delimiter);
		}
	}
}

static void	subvert_spaces(char *str)
{
	subvert_spaces_within_delimiter(str, SINGLE_QUOTE);
	subvert_spaces_within_delimiter(str, DOUBLE_QUOTE);
}

static void	restore_spaces(char **tokens)
{
	char	*token;

	while (*tokens != NULL)
	{
		token = *tokens;
		while (*token != '\0')
		{
			if (*token == NOT_ASCII)
				*token = SPACE;
			token++;
		}
		tokens++;
	}
}

char	**lex_input(char *raw_input)
{
	char	*free_me;
	char	**tokens;

	free_me = ft_strdup(raw_input);
	subvert_spaces(free_me);
	tokens = ft_split(free_me, SPACE);
	restore_spaces(tokens);
	free(free_me);
	return (tokens);
}
