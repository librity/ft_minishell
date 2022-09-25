/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:18:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/24 16:11:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	could_update_pwd(void)
{
	char	*get_result;
	char	new_path[PATH_MAX];

	get_result = getcwd(new_path, sizeof(new_path));
	if (get_result == NULL)
		return (false);
	if (!envht_insert(PWD_KEY, new_path))
		return (false);
	return (true);
}

static bool	could_update_old_pwd(void)
{
	char	*old_pwd;

	old_pwd = envht_get(PWD_KEY);
	if (old_pwd == NULL)
		return (false);
	if (!envht_insert(OLDPWD_KEY, old_pwd))
		return (false);
	return (true);
}

static bool	handled_too_many_args(char **tokens)
{
	if (ft_strarr_len(tokens) <= 2)
		return (false);
	print_location_error(CD, TOO_MANY_ARGS_ERR);
	return (true);
}

int	bi_cd(char **tokens)
{
	if (tokens == NULL)
		return (EXIT_BAD_TOKENS);
	if (handled_too_many_args(tokens))
		return (CD_TOO_MANY_ARGS);
	if (!could_update_pwd())
		return (CD_PWD_UPDATE);
	if (!cd_could_change_dir(tokens))
		return (CD_NO_FILE_OR_DIR);
	if (!could_update_old_pwd())
		return (CD_OLD_PWD_UPDATE);
	if (!could_update_pwd())
		return (CD_PWD_UPDATE);
	return (EXIT_SUCCESS);
}
