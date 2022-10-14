/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 13:31:31 by lpaulo-m         ###   ########.fr       */
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

char	*find_executable(char *command, char **paths)
{
	char	*path;
	int		can_access;

	can_access = access(command, F_OK);
	if (can_access == 0)
		return (command);
	while (*paths)
	{
		path = build_executable_path(*paths, command);
		can_access = access(path, X_OK);
		if (can_access == 0)
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

	path = find_executable(command, paths);
	if (path == NULL)
		die_full(command, NO_FILE_DIR_ERR, 127);
	can_execute = access(path, X_OK);
	if (can_execute < 0)
		die_full(command, PERMISSION_ERR, 126);
	return (path);
}
