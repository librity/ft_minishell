/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 14:09:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_truncate(t_parse_list *plist)
{
	int	fd;

	fd = open_truncate_or_die(get_parse_file_path(plist));
	stdout_to_file(fd);
}

static void	handle_exec(t_parse_list *plist)
{
	execute_or_die(get_parse_tokens(plist));
	exit(EXIT_FAILURE);
}

static void	handle_child(t_parse_list *plist, int pipe[2])
{
	stdout_to_pipe(pipe);
	close_pipe(pipe);
	while (plist != NULL && get_parse_type(plist) != PT_PIPE)
	{
		if (get_parse_type(plist) == PT_TRUNCATE)
			handle_truncate(plist);
		if (get_parse_type(plist) == PT_EXEC)
			handle_exec(plist);
		plist = plist->next;
	}
}

void	execute_fork(t_parse_list *plist)
{
	pid_t	pid;
	int		pipe[2];

	pipe_or_die(pipe);
	pid = fork_or_die();
	if (pid == CHILD_PROCESS_ID)
		handle_child(plist, pipe);
	pipe_to_stdin(pipe);
	close_pipe(pipe);
	waitpid(pid, NULL, 0);
}
