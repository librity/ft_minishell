/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:14:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 19:49:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*insert_around_two(char *line)
{
	insert_delimiter_around_2(line);
	return (line + 2);
}

char	*insert_around_one(char *line)
{
	insert_delimiter_around(line);
	return (line + 1);
}

char	*insert_delimiter(char *line)
{
	*line = DELIMITER;
	return (line);
}
