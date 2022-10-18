/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 18:34:10 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_pwd(char **tokens)
{
	char	*_pwd;

	if (tokens == NULL || *tokens == NULL)
		return (PWD_BAD_TOKENS);
	_pwd = envht_get(PWD_KEY);
	if (_pwd == NULL)
		return (PWD_MISSING_PWD_ENV_VAR);
	printf("%s\n", _pwd);
	return (EXIT_SUCCESS);
}
