/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:46:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/30 14:16:13 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**creat_paths(void);

char	*exec_cmd(void)
{
	int		index;
	char	*cmd;

	index = 0;
	while(rtn_path_index(index))
	{
		rtn_path_index(index);
		if (accessrtn_path_index(index)), F_OK);
			return (rtn_path_index(index));
	}
}
