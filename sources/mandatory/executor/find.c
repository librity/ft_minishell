/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:21:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/13 13:54:22 by wwallas-         ###   ########.fr       */
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
	int		can_execute;

	can_execute = access(command, F_OK);
	if (can_execute == 0)
		return (command);
	while (*paths)
	{
		path = build_executable_path(*paths, command);
		can_execute = access(path, X_OK);
		if (can_execute == 0)
			return (path);
		free(path);
		paths++;
	}
	return (NULL);
}

char	*find_executable_or_die(char *command, char **paths)
{
	char	*path;

	path = find_executable(command, paths);
	if (path == NULL)
		die_full(command, "No such file or directory", 127);
	if (access(path, X_OK) < 0)
		die_full(command, "Permission denied", 126);
	return (path);
}
