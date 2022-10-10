/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original_tty_attr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:32:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/08 13:36:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_termios	*original_tty_attr(void)
{
	return (&c()->original_tty_attr);
}

void	save_tty_flags(void)
{
	int	result;

	result = tcgetattr(STDIN_FILENO, &c()->original_tty_attr);
	if (result == -1)
		die(TTY_GET_ATTR_ERR);
}
