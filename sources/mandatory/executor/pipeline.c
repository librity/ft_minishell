/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/07 17:46:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	execute_pipeline(t_parse_list *pipeline)
{
	int			pipe_count;

	pipe_count = count_parse_pipes(pipeline);
	while (pipe_count > 0)
	{
		execute_pipe(pipeline);
		pipeline = find_next_parse_pipe(pipeline)->next;
		pipe_count--;
	}
	execute_last_pipe(pipeline);
}
