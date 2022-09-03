/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:43 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/02 21:44:16 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_cmd_path(char *cmd)
{
	int		index;
	char	*script;

	index = 0;
	while(rtn_path_index(index))
	{
		script = ft_strjoin(rtn_path_index(index), "/");
		script = ft_strjoin(script, cmd);
		if (!access(script, F_OK))
			return (script);
		index++;
	}
	/*
		COLOCAR UMA MENSAGEM EM WANINGS
	*/
	printf("%s: Command not found\n", cmd);
	return (NULL);
}
