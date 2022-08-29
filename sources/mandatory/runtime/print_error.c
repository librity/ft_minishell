/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:01:58 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 21:03:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define ERROR_PREFIX "ERROR:\t"

void	print_error(char *message)
{
	ft_printf(RB ERROR_PREFIX "%s%s\n" RC, R, message);
}

#define WARNING_PREFIX "WRNNG:\t"

void	print_warning(char *message)
{
	ft_printf(YB WARNING_PREFIX "%s%s\n" RC, Y, message);
}
