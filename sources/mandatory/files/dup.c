/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:39:58 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 15:05:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	dup_or_die(int dup_me)
{
	dup_me = dup(dup_me);
	if (dup_me < 0)
		die_perror(DUP_LOC, EXIT_FAILURE);
	return (dup_me);
}

int	dup2_or_die(int from, int to)
{
	from = dup2(from, to);
	if (from < 0)
		die_perror(DUP2_LOC, EXIT_FAILURE);
	return (from);
}
