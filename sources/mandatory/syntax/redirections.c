/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 18:10:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	has_valid_file_redirection(char **tokens, char *identifier)
{
	char	*filename;

	while (*tokens != NULL)
	{
		if (ft_streq(*tokens, identifier))
		{
			filename = *(tokens + 1);
			if (filename == NULL)
				return (false);
			if (!is_valid_filename(filename))
				return (false);
		}
		tokens++;
	}
	return (true);
}

bool	has_valid_append(char **tokens)
{
	return (has_valid_file_redirection(tokens, APPEND));
}

bool	has_valid_truncate(char **tokens)
{
	return (has_valid_file_redirection(tokens, TRUNCATE));
}

bool	has_valid_read_file(char **tokens)
{
	return (has_valid_file_redirection(tokens, READ_FILE));
}
