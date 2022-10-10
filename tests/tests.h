/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:53:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 15:35:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "minunit.h"
# include "mocks.h"
# include <fcntl.h>
# include <minishell.h>
# include <sys/wait.h>

int		g_stdout_copy;

void	supress_stdout(void)
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

typedef void (*t_test_teardown_cb)(void);
void	write_to_stdin_with_teardown(char *string, t_test_teardown_cb teardown)
{
	pid_t	pid;
	int		_pipe[2];

	pipe(_pipe);
	pid = fork();
	if (pid == CHILD_PROCESS_ID)
	{
		write(_pipe[PIPE_WRITE], string, ft_strlen(string));
		teardown();
		exit(0);
	}
	dup2(_pipe[PIPE_READ], STDIN_FILENO);
	close(_pipe[PIPE_READ]);
	close(_pipe[PIPE_WRITE]);
}

void	write_to_stdin(char *string)
{
	pid_t	pid;
	int		_pipe[2];

	pipe(_pipe);
	pid = fork();
	if (pid == CHILD_PROCESS_ID)
	{
		write(_pipe[PIPE_WRITE], string, ft_strlen(string));
		exit(0);
	}
	dup2(_pipe[PIPE_READ], STDIN_FILENO);
	close(_pipe[PIPE_READ]);
	close(_pipe[PIPE_WRITE]);
}

void assert_strarr_eq(char **expected, char **result)
{
	int i;

	if (expected == NULL && result == NULL)
		return;
	i = 0;
	while (i < (int)ft_strarr_size(expected))
	{
		mu_assert_string_eq(expected[i], result[i]);
		i++;
	}
}

void assert_in_strarr(char **haystack, char *needle)
{
	mu_check(true == ft_str_in_strarr(haystack, needle));
}

void assert_strarr_equivalent(char **expected, char **result)
{
	int i;

	if (expected == NULL && result == NULL)
		return;
	i = 0;
	while (i < (int)ft_strarr_len(expected))
	{
		assert_in_strarr(result, expected[i]);
		i++;
	}
}

void assert_dlist_eq(t_dlist *expected, t_dlist *result, size_t content_size)
{
	void	*expected_content;
	void	*result_result;

	mu_check(ft_dlstsize(expected) == ft_dlstsize(result));

	while (expected != NULL)
	{
		expected_content = expected->content;
		result_result = result->content;
		mu_check(0 == ft_memcmp(expected_content, result_result, content_size));
		expected = expected->next;
		result = result->next;
	}
}

typedef void (*t_content_cb)(void *, void *);
void assert_dlist_equivalent(t_dlist *expected, t_dlist *result, t_content_cb compare)
{
	void	*expected_content;
	void	*result_result;

	mu_check(ft_dlstsize(expected) == ft_dlstsize(result));

	while (expected != NULL)
	{
		expected_content = expected->content;
		result_result = result->content;
		compare(expected_content, result_result);
		expected = expected->next;
		result = result->next;
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
