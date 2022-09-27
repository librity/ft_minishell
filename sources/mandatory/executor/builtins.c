/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:02:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/27 15:03:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	execute_builtin(char **tokens)
{
	int			status;
	t_builtin	builtin_cb;

	builtin_cb = find_builtin(*tokens);
	if (builtin_cb == NULL)
		return (print_warning(EXECUTE_BAD_BUILTIN_WRN));
	status = builtin_cb(tokens);
	set_last_exit(status);
}
