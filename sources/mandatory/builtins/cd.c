/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:18:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 15:59:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	could_update_pwd(void)
{
	char	*result;
	char	new_path[PATH_MAX];

	result = getcwd(new_path, sizeof(new_path));
	if (result == NULL)
		return (false);
	envht_insert(PWD_KEY, new_path);
	return (true);
}

static bool	handled_too_many_args(char **tokens)
{
	if (ft_strarr_len(tokens) <= 2)
		return (false);
	print_location_error(CD, CD_TOO_MANY_ARGS_ERR);
	return (true);
}

int	bi_cd(char **tokens)
{
	if (tokens == NULL)
		return (CD_NULL_TOKENS);
	if (handled_too_many_args(tokens))
		return (CD_TOO_MANY_ARGS);
	if (!cd_could_change_dir(tokens))
		return (CD_NO_FILE_OR_DIR);
	if (!could_update_pwd())
		return (CD_PWD_UPDATE);
	return (EXIT_SUCCESS);
}
