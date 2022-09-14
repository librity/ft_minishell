/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:04:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 12:46:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	open_truncate_or_die(char *path)
{
	int	fd;
	int	flags;

	flags = O_CREAT | O_WRONLY | O_TRUNC;
	fd = open(path, flags, CREATE_PERMISSION);
	if (fd < 0)
		die_perror(path, EXIT_FAILURE);
	return (fd);
}

int	open_append_or_die(char *path)
{
	int	fd;
	int	flags;

	flags = O_CREAT | O_WRONLY | O_APPEND;
	fd = open(path, flags, CREATE_PERMISSION);
	if (fd < 0)
		die_perror(path, EXIT_FAILURE);
	return (fd);
}
