/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/10/07 14:19:26 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*expected;
char	*_stdin;
bool	_bool;

static void	write_to_stdin(char *string)
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

static void	example_setup(void)
{
}
static void	example_teardown(void)
{
}

MU_TEST(get_line_cmd_tst)
{
	write_to_stdin("teste 1 test 2 teste 5\nasdasdas dadsa sdas ds");
	get_line();
	mu_assert_string_eq("teste 1 test 2 teste 5", line_cmd());
	free(line_cmd());

	write_to_stdin(NULL);
	get_line();
	mu_assert_string_eq(NULL, line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq(NULL, line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq(NULL, line_cmd());
	free(line_cmd());
}

MU_TEST(get_basic_tst)
{

	write_to_stdin("teste 1 test 2 teste 5\nasdasdas dadsa sdas ds");
	get_line();
	mu_assert_string_eq("teste 1 test 2 teste 5", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("asdasdas dadsa sdas ds", line_cmd());
	free(line_cmd());
}

MU_TEST(get_medium_tst)
{
	write_to_stdin("\n\n\n\n\nteste 1 test 2 teste 5\n\n\nasdasdas dadsa sdas ds");
	get_line();
	mu_assert_string_eq("teste 1 test 2 teste 5", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("asdasdas dadsa sdas ds", line_cmd());
	free(line_cmd());
}

MU_TEST(get_advanced_tst)
{

	write_to_stdin("\nt\n\ne\ns\nt\ne\n \n1\n \nt\ne\ns\nt\n \n2\n");
	get_line();
	mu_assert_string_eq("t", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("e", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("s", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("t", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("e", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq(" ", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("1", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq(" ", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("t", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("e", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("s", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("t", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq(" ", line_cmd());
	free(line_cmd());

	get_line();
	mu_assert_string_eq("2", line_cmd());
	free(line_cmd());

	get_line();
	mu_check(NULL == line_cmd());

	get_line();
	mu_check(NULL == line_cmd());

	get_line();
	mu_check(NULL == line_cmd());
}

MU_TEST_SUITE(example_suite)
{
	MU_SUITE_CONFIGURE(&example_setup, &example_teardown);

	MU_RUN_TEST(get_line_cmd_tst);
	MU_RUN_TEST(get_basic_tst);
	MU_RUN_TEST(get_medium_tst);
	MU_RUN_TEST(get_advanced_tst);
}

int	main(void)
{
	MU_RUN_SUITE(example_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
