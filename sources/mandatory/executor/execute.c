/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:35:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 13:27:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	initialize_execute(t_exec *exec, char **tokens)
{
	ft_bzero(exec, sizeof(t_exec));
	exec->argv = tokens;
	exec->paths = get_paths_or_die();
	exec->cmd = tokens[0];
	exec->path = find_executable(exec->cmd, exec->paths);
	if (exec->path == NULL)
		die_full(exec->cmd, NO_CMD_ERR, EKEYEXPIRED);
	exec->envp = envht_to_envp();
}

void	execute_or_die(char **tokens)
{
	t_exec	exec;

	if (tokens == NULL)
		die(EXECUTE_NULL_ERR);
	if (*tokens == NULL)
		die(EXECUTE_NULL_ERR);
	initialize_execute(&exec, tokens);
	exec.code = execve(exec.path, exec.argv, exec.envp);
	if (exec.code < 0)
		die_perror(exec.path, EXIT_FAILURE);
}
