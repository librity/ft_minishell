/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 15:41:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**get_paths_or_die(void)
{
	char	*path;
	char	**paths;

	path = envht_get(PATH_KEY);
	if (path == NULL)
		die(PATHS_ERR);
	paths = ft_split(path, ':');
	if (paths == NULL)
		die(PATHS_ERR);
	return (paths);
}

static char	*build_executable_path(char *path, char *command)
{
	char	*executable;

	executable = ft_strjoin(path, "/");
	executable = ft_strjoin_free(executable, command);
	return (executable);
}

char	*find_in_paths(char *command, char **paths)
{
	char	*path;
	int		file_exists;

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
