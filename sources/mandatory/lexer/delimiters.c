/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:14:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 19:19:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*insert_pipe_delimiters(char *line)
{
	insert_char_around(line, DELIMITER);
	return (line + 1);
}

char	*insert_greater_than_delimiters(char *line)
{
	if (*(line + 1) == GREATER_THAN)
	{
		insert_char_after(line + 1, DELIMITER);
		insert_char_before(line, DELIMITER);
		return (line + 2);
	}
	insert_char_around(line, DELIMITER);
	return (line + 1);
}

char	*insert_less_than_delimiters(char *line)
{
	if (*(line + 1) == LESS_THAN)
	{
		insert_char_after(line + 1, DELIMITER);
		insert_char_before(line, DELIMITER);
		return (line + 2);
	}
	insert_char_around(line, DELIMITER);
	return (line + 1);
}

char	*insert_delimiter(char *line)
{
	*line = DELIMITER;
	return (line);
}
