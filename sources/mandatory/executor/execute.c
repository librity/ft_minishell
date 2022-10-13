/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:39:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/13 11:31:16 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_pipeline(t_parse_list *pipeline)
{
	if (handled_single_builtin(pipeline))
		return ;
	execute_pipeline(pipeline);
}

void	execute(t_parse_list *pipeline)
{
	t_proc_fds	ioe;

	save_ioe(&ioe);
	handle_pipeline(pipeline);
	restore_ioe(&ioe);
}
