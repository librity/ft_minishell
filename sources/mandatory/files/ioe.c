/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:39:58 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 15:05:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	save_ioe(t_proc_fds *ioe)
{
	ioe->input = dup_or_die(STDIN_FILENO);
	ioe->output = dup_or_die(STDOUT_FILENO);
	ioe->error = dup_or_die(STDERR_FILENO);
}

void	restore_ioe(t_proc_fds *ioe)
{
	dup2_or_die(ioe->input, STDIN_FILENO);
	close_or_die(ioe->input);
	dup2_or_die(ioe->output, STDOUT_FILENO);
	close_or_die(ioe->output);
	dup2_or_die(ioe->error, STDERR_FILENO);
	close_or_die(ioe->error);
}
