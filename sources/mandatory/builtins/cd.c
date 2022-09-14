/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:18:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/14 15:05:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	could_change_dir(char *path)
{
	int	result;

	result = chdir(path);
	if (result < 0)
		return (false);
	return (true);
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

bool	cd(char **tokens)
{
	char	*path;

	if (ft_strarr_len(tokens) != 2)
		return (false);
	path = tokens[1];
	if (!could_change_dir(path))
		return (false);
	if (!could_update_pwd())
		return (false);
	return (true);
}
