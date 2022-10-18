/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:30:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	can_execute_or_die(char *path)
{
	int	can_execute;

	can_execute = access(path, X_OK);
	if (can_execute < 0)
		die_full(path, PERMISSION_ERR, 126);
}

static char	*handle_relative_or_absolute_path(char *path)
{
	int	file_exists;

	file_exists = access(path, F_OK);
	if (file_exists != 0)
		die_full(path, NO_FILE_DIR_ERR, 127);
	if (is_directory(path))
		die_full(path, IS_DIR_ERR, 126);
	can_execute_or_die(path);
	return (path);
}

static char	*handle_raw_command(char *command, char **paths)
{
	char	*path;

	path = find_in_paths(command, paths);
	if (path == NULL || is_directory(path))
		die_full(command, NO_CMD_ERR, 127);
	can_execute_or_die(path);
	return (path);
}

char	*find_executable_or_die(char *command, char **paths)
{
	if (is_relative_or_absolute_path(command))
		return (handle_relative_or_absolute_path(command));
	return (handle_raw_command(command, paths));
}
