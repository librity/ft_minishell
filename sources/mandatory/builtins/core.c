/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:18:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 18:32:47 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_builtin	find_builtin(char *name)
{
	const t_dict	*_builtins[] = {
		&(const t_dict){BI_ECHO, bi_echo},
		&(const t_dict){CD, bi_cd},
		&(const t_dict){PWD, bi_pwd},
		&(const t_dict){EXPORT, bi_export},
		&(const t_dict){UNSET, bi_unset},
		&(const t_dict){ENV, bi_env},
		&(const t_dict){EXIT, bi_exit},
		&(const t_dict){HELP, bi_help},
		NULL};

	return (ft_dict_find(_builtins, name));
}

bool	is_builtin(char *name)
{
	if (find_builtin(name) == NULL)
		return (false);
	return (true);
}

int	execute_builtin(char **tokens)
{
	t_builtin	builtin_cb;

	builtin_cb = find_builtin(*tokens);
	if (builtin_cb == NULL)
	{
		print_error(BAD_BUILTIN_ERR);
		return (EXIT_FAILURE);
	}
	return (builtin_cb(tokens));
}
