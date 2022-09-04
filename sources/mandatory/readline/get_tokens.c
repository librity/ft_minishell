/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:53:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/04 00:26:19 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*pwd(void)
{
	char	path[MAX_PATH];

	return (ft_strjoin(getcwd(path, MAX_PATH), "$ "));
}

void	get_tokens(void)
{
	char	*tmp;

	tmp = pwd();
	get_cmd_line(tmp);
	vf_clone_quote(line_cmd());
	add_history(line_cmd());
	c()->tokens = lex();
	free(tmp);
}

