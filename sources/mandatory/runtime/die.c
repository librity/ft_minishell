/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:59:43 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 21:00:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	die(char *error_message)
{
	free_memory();
	print_error(error_message);
	exit(EXIT_FAILURE);
}

void	free_and_die(void *free_me, char *error_message)
{
	free(free_me);
	die(error_message);
}

void	free_arr_and_die(char **free_me, char *error_message)
{
	ft_free_strarr(free_me);
	die(error_message);
}
