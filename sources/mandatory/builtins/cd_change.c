/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:18:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 16:00:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*resolve_path(char **tokens)
{
	char	*path;

	path = tokens[1];
	if (path == NULL)
		path = envht_get(HOME_KEY);
	return (path);
}

static void	print_path_err(char *path)
{
	char	*message;

	message = ft_strdup(path);
	if (path == NULL)
		message = ft_strjoin_free(message, ": " CD_NULL_PATH_ERR);
	else
		message = ft_strjoin_free(message, ": " NO_FILE_DIR_ERR);
	print_location_error(CD, message);
	free(message);
}

bool	cd_could_change_dir(char **tokens)
{
	char	*path;
	int		result;

	path = resolve_path(tokens);
	result = chdir(path);
	if (result >= 0)
		return (true);
	print_path_err(path);
	return (false);
}
