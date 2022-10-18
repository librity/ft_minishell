/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_at_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:01:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 13:13:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	at_single_quote(char *line)
{
	return (*line == SINGLE_QUOTE);
}

bool	at_double_quote(char *line)
{
	return (*line == DOUBLE_QUOTE);
}

bool	at_pipe(char *line)
{
	return (*line == VERTICAL_BAR);
}

bool	at_space(char *line)
{
	return (*line == SPACE);
}

bool	at_dollar(char *line)
{
	if (line == NULL || *line == 0)
		return (false);
	if (ft_strchr(BAD_DOLLAR_SEQUENCE, line[1]))
		return (false);
	return (*line == DOLLAR);
}
