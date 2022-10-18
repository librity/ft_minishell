/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:39:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:02:44 by lpaulo-m         ###   ########.fr       */
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
	save_ioe(ioe());
	handle_pipeline(pipeline);
	restore_ioe(ioe());
}
