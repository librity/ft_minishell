/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:13:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/01 13:16:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define ERROR_PREFIX "ERROR:\t"

void	print_error(char *message)
{
	ft_printf(RB ERROR_PREFIX R "%s\n" RC, message);
}

#define WARNING_PREFIX "WRNNG:\t"

void	print_warning(char *message)
{
	ft_printf(YB WARNING_PREFIX Y "%s\n" RC, message);
}
