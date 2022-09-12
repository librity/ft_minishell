/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/12 13:00:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	first_is_pipe(char **tokens)
{
	char	*first;

	first = *tokens;
	if (first == NULL)
		return (false);
	if (ft_streq(first, PIPE))
		return (true);
	return (false);
}

bool	has_valid_pipe(char **tokens)
{
	char	*next;

	if (first_is_pipe(tokens))
		return (false);
	while (*tokens != NULL)
	{
		if (ft_streq(*tokens, PIPE))
		{
			next = *(tokens + 1);
			if (next == NULL)
				return (false);
			if (ft_streq(next, PIPE))
				return (false);
		}
		tokens++;
	}
	return (true);
}

char	**find_next_pipe(char **tokens)
{
	if (tokens == NULL)
		return (NULL);
	while (*tokens != NULL)
	{
		if (ft_streq(*tokens, PIPE))
			return (tokens);
		tokens++;
	}
	return (tokens);
}

int	count_pipes(char **tokens)
{
	int	pipe_count;

	if (tokens == NULL)
		return (0);
	pipe_count = 0;
	while (*tokens != NULL)
	{
		if (ft_streq(*tokens, PIPE))
			pipe_count++;
		tokens++;
	}
	return (pipe_count);
}
