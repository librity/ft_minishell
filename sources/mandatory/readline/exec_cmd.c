/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:46:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/31 11:45:44 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**creat_paths(void);

char	*exec_cmd(void)
{
	int		index;
	char	*script;

	index = 0;
	while(rtn_path_index(index))
	{
		script = ft_strjoin(rtn_path_index(index), "/");
		printf("cmd = %s\n", script);
		if (access(rtn_path_index(index), F_OK))
			printf("eu\n");
			//return (rtn_path_index(index));
		index++;
	}
	return (NULL);
}
