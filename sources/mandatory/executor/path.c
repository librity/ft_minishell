/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:13:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 15:26:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_absolute_path(char *path)
{
	return (ft_starts_with(path, "/"));
}

bool	is_relative_path(char *path)
{
	return (ft_starts_with(path, "./") || ft_starts_with(path, "../"));
}

bool	is_relative_or_absolute_path(char *path)
{
	return (is_relative_path(path) || is_absolute_path(path));
}
