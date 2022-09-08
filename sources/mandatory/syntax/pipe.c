/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 19:00:46 by lpaulo-m         ###   ########.fr       */
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
