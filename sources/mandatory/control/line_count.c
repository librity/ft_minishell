/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:49:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:52:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	line_count(void)
{
	return (c()->line_count);
}

void	increase_line_count(void)
{
	c()->line_count++;
}
