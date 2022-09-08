/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 17:39:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_valid_append(char **tokens)
{
	char	*filename;

	while (*tokens != NULL)
	{
		if (ft_streq(*tokens, APPEND))
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
