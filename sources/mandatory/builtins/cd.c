/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:18:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 15:09:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	could_change_dir(char *path)
{
	int		result;
	char	*message;

	result = chdir(path);
	if (result >= 0)
		return (true);
	message = ft_strdup(path);
	message = ft_strjoin_free(message, ": " CD_CHANGE_DIR_ERR);
	print_location_error(CD, message);
	free(message);
	return (false);
}

static bool	could_update_pwd(void)
{
	char	*result;
	char	new_path[PATH_MAX];

	result = getcwd(new_path, sizeof(new_path));
	if (result == NULL)
		return (false);
	envht_insert(PWD_KEY, new_path);
	return (true);
}

static bool	handled_too_many_args(char **tokens)
{
	if (ft_strarr_len(tokens) <= 2)
		return (false);
	print_location_error(CD, CD_TOO_MANY_ARGS_ERR);
	return (true);
}

int	bi_cd(char **tokens)
{
	char	*path;

	if (tokens == NULL)
		return (CD_NULL);
	if (handled_too_many_args(tokens))
		return (CD_TOO_MANY_ARGS);
	path = tokens[1];
	if (!could_change_dir(path))
		return (CD_NO_FILE_OR_DIR);
	if (!could_update_pwd())
		return (CD_PWD_UPDATE);
	return (CD_SUCCESS);
}
