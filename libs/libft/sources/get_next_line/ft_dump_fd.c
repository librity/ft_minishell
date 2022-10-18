/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:36:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 20:21:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Read from a file descriptor until GNL_FOUND_EOF or GNL_ERROR.
 *
 * @param fd The file descriptor to be read.
 */
void	ft_dump_fd(int fd)
{
	int		status;
	char	*line;

	while (true)
	{
		status = ft_get_next_line(fd, &line);
		if (status == GNL_ERROR)
			break ;
		ft_putendl(line);
		free(line);
		if (status == GNL_FOUND_EOF)
			break ;
	}
}
