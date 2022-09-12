/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/12 12:58:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**operators(void)
{
	static char	*_operators[] = {
		PIPE,
		TRUNCATE, APPEND,
		READ_FILE, HEREDOC,
		NULL};

	return (_operators);
}

bool	is_operator(char *token)
{
	return (ft_str_in_strarr(operators(), token));
}

char	**find_next_operator(char **tokens)
{
	if (tokens == NULL)
		return (NULL);
	while (*tokens != NULL)
	{
		if (is_operator(*tokens))
			return (tokens);
		tokens++;
	}
	return (tokens);
}
