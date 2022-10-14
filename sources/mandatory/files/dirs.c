/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:12:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 14:13:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_directory(char *path)
{
	t_stat	_stat;
	int		result;

	result = stat(path, &_stat);
	if (result != 0)
		die_perror(STAT_LOC, USE_ERRNO);
	if (_stat.st_mode & S_IFDIR)
		return (true);
	return (false);
}
