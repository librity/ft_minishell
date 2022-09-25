/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/24 16:03:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_pwd(char **tokens)
{
	char	*_pwd;

	if (tokens == NULL || *tokens == NULL)
		return (PWD_BAD_TOKENS);
	if (ft_strarr_len(tokens) != 1)
		return (PWD_TOO_MANY_ARGS);
	_pwd = envht_get(PWD_KEY);
	if (_pwd == NULL)
		return (PWD_MISSING_PWD_ENV_VAR);
	printf("%s\n", _pwd);
	return (EXIT_SUCCESS);
}
