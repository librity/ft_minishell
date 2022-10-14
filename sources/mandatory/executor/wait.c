/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 16:49:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	wait_or_die(int *stats)
{
	pid_t	result;

	result = wait(stats);
	if (result < 0)
		die_perror(WAIT_LOC, USE_ERRNO);
	return (result);
}

pid_t	waitpid_or_die(pid_t pid, int *stats, int options)
{
	pid_t	result;

	result = waitpid(pid, stats, options);
	if (result < 0)
		die_perror(WAITPID_LOC, USE_ERRNO);
	return (result);
}
