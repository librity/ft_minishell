/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:32:52 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/30 14:12:33 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initalize_paths(void)
{
	c()->paths = ft_split(getenv("PATH"), ':');
}

char	*rtn_path_index(index)
{
	return (c()->paths[index]);
}
