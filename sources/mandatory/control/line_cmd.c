/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:39:57 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 17:40:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*line_cmd(void)
{
	return (c()->line_cmd);
}

void	set_line_cmd(char *input)
{
	c()->line_cmd = input;
}
