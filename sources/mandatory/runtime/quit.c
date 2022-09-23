/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:01:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 14:04:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	cleanup(void)
{
	cleanup_shell();
}

void	quit(void)
{
	cleanup();
	exit(EXIT_SUCCESS);
}
