/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:35:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/16 01:32:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	initialize_execve(t_execve *exec, char **tokens)
{
	ft_bzero(exec, sizeof(t_execve));
	exec->argv = tokens;
	exec->paths = get_paths_or_die();
	exec->cmd = tokens[0];
	exec->path = find_executable_or_die(exec->cmd, exec->paths);
	exec->envp = envht_to_envp();
}

void	execve_or_die(char **tokens)
{
	t_execve	exec;

	if (tokens == NULL)
		die(EXECUTE_NULL_ERR);
	if (*tokens == NULL)
		die(EXECUTE_NULL_ERR);
	initialize_execve(&exec, tokens);
	exec.code = execve(exec.path, exec.argv, exec.envp);
	if (exec.code < 0)
		die_perror(exec.path, USE_ERRNO);
	quit_status(exec.code);
}
