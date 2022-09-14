/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/14 15:48:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	pwd(char **tokens)
{
	char	*_pwd;

	if (tokens == NULL || *tokens == NULL)
		return (false);
	if (ft_strarr_len(tokens) != 1)
		return (false);
	_pwd = envht_get(PWD_KEY);
	if (_pwd == NULL)
		return (false);
	printf("%s\n", _pwd);
	return (true);
}
