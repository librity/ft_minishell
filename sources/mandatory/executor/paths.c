/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/12 22:44:45 by lpaulo-m         ###   ########.fr       */
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
