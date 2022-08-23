/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:36:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 01:45:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*skip_or_delimit(char *input)
{
	if (*input == SINGLE_QUOTE)
		return (ft_strchr(++input, SINGLE_QUOTE));
	if (*input == DOUBLE_QUOTE)
		return (ft_strchr(++input, DOUBLE_QUOTE));
	if (*input == SPACE)
		*input = DELIMITER;
	return (input);
}

static void	insert_trivial_delimiters(char *input)
{
	while (input != NULL && *input != '\0')
	{
		input = skip_or_delimit(input);
		if (input != NULL)
			input++;
	}
}

char	**tokenize(char *input)
{
	char	*free_me;
	char	**tokens;

	free_me = ft_strdup(input);
	insert_trivial_delimiters(free_me);
	tokens = ft_split(free_me, DELIMITER);
	free(free_me);
	return (tokens);
}
