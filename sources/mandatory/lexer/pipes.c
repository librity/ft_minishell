/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:45:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 15:45:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
