/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:53:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 18:49:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "minunit.h"
# include <fcntl.h>
# include <minishell.h>

int		g_stdout_copy;

void	stdout_to_devnull(void)
{
	int	dev_null;

	g_stdout_copy = dup(STDOUT_FILENO);
	dev_null = open("/dev/null", O_RDWR);
	dup2(dev_null, STDOUT_FILENO);
	close(dev_null);
}

void	restore_stdout(void)
{
	dup2(g_stdout_copy, STDOUT_FILENO);
	close(g_stdout_copy);
}

static void assert_strarr_eq(char **_expected, char **_result)
{
	int i;

	i = 0;
	while (i < (int)ft_strarr_size(_expected))
	{
		mu_assert_string_eq(_expected[i], _result[i]);
		i++;
	}
}

#endif
