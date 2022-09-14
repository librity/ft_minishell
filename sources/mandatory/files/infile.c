/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/12 22:33:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	exists_or_die(char *path)
{
	int	exists;

	exists = access(path, F_OK);
	if (exists < 0)
		die_perror(path, EXIT_FAILURE);
}

static void	read_or_die(char *path)
{
	int	can_read;

	can_read = access(path, R_OK);
	if (can_read < 0)
		die_perror(path, EXIT_SUCCESS);
}

int	open_file_or_die(char *path)
{
	int	open_fd;
	int	open_flags;

	open_flags = O_RDONLY;
	open_fd = open(path, open_flags);
	if (open_fd < 0)
		die_perror(path, EXIT_FAILURE);
	return (open_fd);
}

int	open_infile_or_die(char *path)
{
	exists_or_die(path);
	read_or_die(path);
	return (open_file_or_die(path));
}
