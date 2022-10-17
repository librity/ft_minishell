/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:47:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:18:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_hdoc_interrupt_signal(int signal)
{
	if (debug())
		ft_debug("handle_hdoc_interrupt_signal: signal: %d", signal);
	else
		printf("\n");
	quit();
}

void	set_interrupt_hdoc_signal_hook(void)
{
	set_signal_hook(signal_action(), handle_hdoc_interrupt_signal, SIGINT);
}

void	set_hdoc_hooks(void)
{
	set_interrupt_hdoc_signal_hook();
}


static void	get_hdoc_stream(char *delimiter, int pipe[2])
{
	int		status;
	char	*line;

	while (true)
	{
		ft_putstr_fd(HDOC_FEED, ioe_out());
		status = ft_get_next_line(ioe_in(), &line);
		if (status == GNL_ERROR)
			die_perror(HEREDOC_LOC, EXIT_FAILURE);
		if (ft_streq(line, delimiter))
		{
			free(line);
			close_pipe(pipe);
			quit();
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

	disable_quit_signal();
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
}
