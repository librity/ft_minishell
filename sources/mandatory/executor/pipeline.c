/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/16 01:14:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	execute_first_pipe(t_parse_list *pipeline, pid_t *pids, int **pipes)
{
	pids[0] = fork_or_die();
	if (pids[0] != CHILD_PROCESS_ID)
		return ;
	set_fork_hooks();
	stdout_to_pipe(pipes[0]);
	close_pipes(pipes);
	handle_fork_sequence(pipeline);
}

void	execute_pipe(t_parse_list *pipeline,
			pid_t *pids, int **pipes, int index)
{
	int	*in_pipe;
	int	*out_pipe;

	pids[index] = fork_or_die();
	if (pids[index] != CHILD_PROCESS_ID)
		return ;
	set_fork_hooks();
	in_pipe = pipes[index - 1];
	out_pipe = pipes[index];
	pipe_to_stdin(in_pipe);
	stdout_to_pipe(out_pipe);
	close_pipes(pipes);
	handle_fork_sequence(pipeline);
}

void	execute_last_pipe(t_parse_list *pipeline,
			pid_t *pids, int **pipes, int index)
{
	int	*in_pipe;

	pids[index] = fork_or_die();
	if (pids[index] != CHILD_PROCESS_ID)
		return ;
	set_fork_hooks();
	in_pipe = pipes[index - 1];
	pipe_to_stdin(in_pipe);
	close_pipes(pipes);
	handle_fork_sequence(pipeline);
}

void	execute_single_pipe(t_parse_list *pipeline, pid_t *pids)
{

	pids[0] = fork_or_die();
	if (pids[0] != CHILD_PROCESS_ID)
		return ;
	set_fork_hooks();
	handle_fork_sequence(pipeline);
}

void	execute_pipeline(t_parse_list *pipeline)
{
	int		pipe_count;
	int		pid_count;
	int		index;
	pid_t	*pids;
	int		**pipes;

	pipe_count = count_parse_pipes(pipeline);
	pid_count = pipe_count + 1;
	pids = ft_clalloc(lalloc(), sizeof(pid_t), pid_count);
	pipes = ft_clalloc(lalloc(), sizeof(int *), pipe_count + 1);
	index = 0;
	while (index < pipe_count)
	{
		pipes[index] = ft_clalloc(lalloc(), sizeof(int), 2);
		pipe_or_die(pipes[index]);
		index++;
	}
	pipes[index] = NULL;




	if (pipe_count == 0)
		execute_single_pipe(pipeline, pids);
	else
	{
		execute_first_pipe(pipeline, pids, pipes);
		pipeline = find_next_parse_pipe(pipeline)->next;
		index = 1;
		while (index < pipe_count)
		{
			execute_pipe(pipeline, pids, pipes, index);
			pipeline = find_next_parse_pipe(pipeline)->next;
			index++;
		}
		execute_last_pipe(pipeline, pids, pipes, index);
		close_pipes(pipes);
	}




	int		fork_status;
	int		exit_status;
	index = 0;
	while (index < pid_count)
	{
		waitpid_or_die(pids[index], &fork_status, 0);
		exit_status = WEXITSTATUS(fork_status);
		set_last_exit(exit_status);
		index++;
	}

}
