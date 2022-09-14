/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:18:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/14 14:33:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**builtins(void)
{
	static char	*builtins[] = {
		ECHO, CD, PWD, EXPORT, UNSET, ENV, EXIT,
		NULL};

	return (builtins);
}

bool	is_builtin(char *cmd)
{
	return (ft_str_in_strarr(builtins(), cmd));
}
