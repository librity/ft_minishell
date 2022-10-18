/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:36:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:24:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Reads an entire line from a file indexed by a file descriptor fd,
 * then alocates a string with the contents of that line
 * without the linebreak '\n' and points *line to it.
 *
 * Returns 1 if successfull, 0 if it reached the end of the file
 * and -1 if an error occurred.
 *
 * @param fd The file descriptor to read from.
 * @param line The line pointer address.
 * @return int The exit status.
 */
int	ft_gnl(int fd, char **line)
{
	return (ft_get_next_line(fd, line));
}
