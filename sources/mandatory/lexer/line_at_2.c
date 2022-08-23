/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_at_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:01:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 20:02:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	at_truncate(char *line)
{
	return (*line == GREATER_THAN);
}

bool	at_append(char *line)
{
	return (*line == GREATER_THAN && *(line + 1) == GREATER_THAN);
}

bool	at_read_file(char *line)
{
	return (*line == LESS_THAN);
}

bool	at_heredoc(char *line)
{
	return (*line == LESS_THAN && *(line + 1) == LESS_THAN);
}
