/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:53:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 23:00:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "minunit.h"
# include <fcntl.h>
# include <minishell.h>
# include <sys/wait.h>

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

void assert_strarr_eq(char **_expected, char **_result)
{
	int i;

	i = 0;
	while (i < (int)ft_strarr_size(_expected))
	{
		mu_assert_string_eq(_expected[i], _result[i]);
		i++;
	}
}

void assert_in_strarr(char **haystack, char *needle)
{
	mu_check(true == ft_str_in_strarr(haystack, needle));
}

void assert_strarr_equivalent(char **_expected, char **_result)
{
	int i;

	i = 0;
	while (i < (int)ft_strarr_len(_expected))
	{
		assert_in_strarr(_result, _expected[i]);
		i++;
	}
}

typedef void (*t_test_die_callback)(void);
void test_die(t_test_die_callback should_die)
{
	pid_t pid;
	int wstatus;
	pid = fork();

	if (pid == 0)
	{
		should_die();
	}
	mu_check(pid == wait(&wstatus));
	mu_check(EXIT_FAILURE == WEXITSTATUS(wstatus));
}

#endif
