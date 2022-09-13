/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 19:42:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_read_file(t_parse_list *node)
{
	char	*path;
	int		fd;

	path = get_parse_file_path(node);
	fd = open_infile_or_die(path);
	file_to_stdin(fd);
}

static void	handle_heredoc(t_parse_list *node)
{
	char	*delimiter;

	delimiter = get_parse_delimiter(node);
	hdoc_to_stdin(delimiter);
}

static void	handle_truncate(t_parse_list *node)
{
	char	*file_path;
	int		fd;

	file_path = get_parse_file_path(node);
	fd = open_truncate_or_die(file_path);
	stdout_to_file(fd);
}

static void	handle_append(t_parse_list *node)
{
	char	*file_path;
	int		fd;

	file_path = get_parse_file_path(node);
	fd = open_append_or_die(file_path);
	stdout_to_file(fd);
}

static void	handle_exec(t_parse_list *node)
{
	char	**tokens;

	tokens = get_parse_tokens(node);
	execute_or_die(tokens);
	exit(EXIT_FAILURE);
}

static void	handle_pipe(t_parse_list *node)
{
	t_parse_type	type;

	while (node != NULL && get_parse_type(node) != PT_PIPE)
	{
		type = get_parse_type(node);
		if (type == PT_READ_FILE)
			handle_read_file(node);
		if (type == PT_HEREDOC)
			handle_heredoc(node);
		if (type == PT_TRUNCATE)
			handle_truncate(node);
		if (type == PT_APPEND)
			handle_append(node);
		if (type == PT_EXEC)
			handle_exec(node);
		node = node->next;
	}
}

static void	handle_child(t_parse_list *pipeline, int pipe[2])
{
	stdout_to_pipe(pipe);
	close_pipe(pipe);
	handle_pipe(pipeline);
}

void	execute_pipe(t_parse_list *pipeline)
{
	pid_t	pid;
	int		pipe[2];

	pipe_or_die(pipe);
	pid = fork_or_die();
	if (pid == CHILD_PROCESS_ID)
		handle_child(pipeline, pipe);
	pipe_to_stdin(pipe);
	close_pipe(pipe);
	waitpid(pid, NULL, 0);
}

static void	handle_last_child(t_parse_list *pipeline)
{
	handle_pipe(pipeline);
}

void	execute_last_pipe(t_parse_list *pipeline)
{
	pid_t	pid;

	pid = fork_or_die();
	if (pid == CHILD_PROCESS_ID)
		handle_last_child(pipeline);
	waitpid(pid, NULL, 0);
}
