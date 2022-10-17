/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 15:38:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_valid_heredoc(char **tokens)
{
	char	*delimiter;

	while (*tokens != NULL)
	{
		if (ft_streq(*tokens, HEREDOC))
		{
			delimiter = *(tokens + 1);
			if (delimiter == NULL || is_operator(delimiter))
			{
				print_syntax_error(*tokens);
				return (false);
			}
		}
		tokens++;
	}
	return (true);
}
