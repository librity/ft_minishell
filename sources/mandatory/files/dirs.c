/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:12:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 15:28:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_directory(char *path)
{
	t_stat	path_stats;
	int		result;

	if (path == NULL)
		return (false);
	result = stat(path, &path_stats);
	if (result != 0)
		die_perror(STAT_LOC, USE_ERRNO);
	if (path_stats.st_mode & S_IFDIR)
		return (true);
	return (false);
}
