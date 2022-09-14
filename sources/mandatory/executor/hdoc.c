/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:47:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/14 14:06:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_hdoc_stream(char *delimiter, int pipe[2])
{
	int		status;
	char	*line;

	while (true)
	{
		ft_putstr(HDOC_FEED);
		status = ft_get_next_line(STDIN_FILENO, &line);
		if (status == GNL_ERROR)
			die_perror(HEREDOC_LOCATION_ERR, EXIT_FAILURE);
		if (ft_streq(line, delimiter))
		{
			free(line);
			shell_exit();
		}
		line = ft_strjoin_free(line, "\n");
		str_to_pipe(pipe, line);
		free(line);
	}
}

void	hdoc_to_stdin(char *delimiter)
{
	pid_t	pid;
	int		pipe[2];

	ft_debug("delimiter= %s", delimiter);
	if (delimiter == NULL)
		die(HEREDOC_DELIMITER_ERR);
	pipe_or_die(pipe);
	pid = fork_or_die();
	if (pid != CHILD_PROCESS_ID)
	{
		get_hdoc_stream(delimiter, pipe);
		return ;
	}
	pipe_to_stdin(pipe);
	close_pipe(pipe);
	wait(NULL);
}
