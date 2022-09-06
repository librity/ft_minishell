/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:34:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 18:24:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_valid_quotes(char *line)
{
	int	sq_count;
	int	dq_count;

	sq_count = 0;
	dq_count = 0;
	while (*line)
	{
		if (*line == SINGLE_QUOTE && dq_count % 2 == 0)
			sq_count++;
		if (*line == DOUBLE_QUOTE && sq_count % 2 == 0)
			dq_count++;
		line++;
	}
	if (sq_count % 2 == 1 || dq_count % 2 == 1)
		return (false);
	return (true);
}
