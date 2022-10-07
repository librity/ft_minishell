/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:53:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/07 11:14:33 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*pwd(void)
{
	char	path[MAX_PATH];

	return (ft_strjoin(getcwd(path, MAX_PATH), "$ "));
}

void	get_line(void)
{
	char	*path;
	char	*cmd_line;

	path = pwd();
	cmd_line = get_cmd_line(path);
	set_line_cmd(cmd_line);
	//vf_clone_quote(line_cmd());
	add_history(line_cmd());
	free(path);
}

