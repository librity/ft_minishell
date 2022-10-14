/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 14:43:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*build_executable_path(char *path, char *command)
{
	char	*executable;

	executable = ft_strjoin(path, "/");
	executable = ft_strjoin_free(executable, command);
	return (executable);
}

char	*find_file(char *command, char **paths)
{
	char	*path;
	int		file_exists;

	file_exists = access(command, F_OK);
	if (file_exists == 0)
		return (command);
	while (*paths)
	{
		path = build_executable_path(*paths, command);
		file_exists = access(path, F_OK);
		if (file_exists == 0)
			return (path);
		free(path);
		paths++;
	}
	return (NULL);
}

char	*find_executable_or_die(char *command, char **paths)
{
	char	*path;
	int		can_execute;

	path = find_file(command, paths);
	ft_bdebug(debug(), "path = %s", path);
	if (path == NULL)
	{
		if (ft_starts_with(command, "./"))
			die_full(command, "No such file or directory", 127);
		die_full(command, "command not found", 127);
	}
	if (is_directory(path))
		die_full(command, IS_DIR_ERR, 126);
	can_execute = access(path, X_OK);
	if (can_execute < 0)
		die_full(command, PERMISSION_ERR, 126);
	return (path);
}
