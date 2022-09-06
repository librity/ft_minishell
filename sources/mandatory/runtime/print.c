/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:13:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 14:27:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_error(char *message)
{
	printf(RB PRINT_ERROR_PREFIX R "%s\n" RC, message);
}

void	print_warning(char *message)
{
	printf(YB PRINT_WARNING_PREFIX Y "%s\n" RC, message);
}
