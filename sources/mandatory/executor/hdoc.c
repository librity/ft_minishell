/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:47:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 13:59:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_eof_message(char *delimiter)
{
	char	*line_count_string;

	line_count_string = ft_itoa(line_count());
	ft_putstr_fd(HDOC_EOF_MSG_1, ioe_out());
	ft_putstr_fd(line_count_string, ioe_out());
	ft_putstr_fd(HDOC_EOF_MSG_2, ioe_out());
	ft_putstr_fd(delimiter, ioe_out());
	ft_putstr_fd(HDOC_EOF_MSG_3, ioe_out());
	free(line_count_string);
}

static void	quit_hdoc(int pipe[2], char *line)
{
	free(line);
	close_pipe(pipe);
	quit();
}

static void	get_hdoc_stream(char *delimiter, int pipe[2])
{
	char	*line;

	while (true)
	{
		line = readline(HDOC_FEED);
		if (line == NULL)
		{
			print_eof_message(delimiter);
			quit_hdoc(pipe, line);
		}
		if (ft_streq(line, delimiter))
			quit_hdoc(pipe, line);
		line = ft_strjoin_free(line, "\n");
		str_to_pipe(pipe, line);
		free(line);
	}
}

void	hdoc_to_stdin(char *delimiter)
{
	pid_t	pid;
	int		pipe[2];

	disable_signals();
	if (delimiter == NULL)
		die(HEREDOC_DELIMITER_ERR);
	pipe_or_die(pipe);
	pid = fork_or_die();
	if (pid == CHILD_PROCESS_ID)
	{
		set_hdoc_hooks();
		get_hdoc_stream(delimiter, pipe);
		return ;
	}
	pipe_to_stdin(pipe);
	close_pipe(pipe);
	waitpid_or_die(pid, NULL, 0);
	set_fork_hooks();
}
