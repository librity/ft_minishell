/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 14:52:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_read_file(t_parse_list *plist)
{
	char	*path;
	int		fd;

	path = get_parse_file_path(plist);
	fd = open_infile_or_die(path);
	file_to_stdin(fd);
}

static void	handle_heredoc(t_parse_list *plist)
{
	char	*delimiter;

	delimiter = get_parse_delimiter(plist);
	hdoc_to_stdin(delimiter);
}

static void	handle_truncate(t_parse_list *plist)
{
	char	*file_path;
	int		fd;

	file_path = get_parse_file_path(plist);
	fd = open_truncate_or_die(file_path);
	stdout_to_file(fd);
}

static void	handle_append(t_parse_list *plist)
{
	char	*file_path;
	int		fd;

	file_path = get_parse_file_path(plist);
	fd = open_append_or_die(file_path);
	stdout_to_file(fd);
}

static void	handle_exec(t_parse_list *plist)
{
	char	**tokens;

	tokens = get_parse_tokens(plist);
	execute_or_die(tokens);
	exit(EXIT_FAILURE);
}

static void	handle_child(t_parse_list *plist, int pipe[2])
{
	t_parse_type	type;

	stdout_to_pipe(pipe);
	close_pipe(pipe);
	while (plist != NULL && get_parse_type(plist) != PT_PIPE)
	{
		type = get_parse_type(plist);
		if (type == PT_READ_FILE)
			handle_read_file(plist);
		if (type == PT_HEREDOC)
			handle_heredoc(plist);
		if (type == PT_TRUNCATE)
			handle_truncate(plist);
		if (type == PT_APPEND)
			handle_append(plist);
		if (type == PT_EXEC)
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
