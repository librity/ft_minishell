/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_at_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:01:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 10:50:05 by wwallas-         ###   ########.fr       */
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
	return (*line == DOLLAR);
}
