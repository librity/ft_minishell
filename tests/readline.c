/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 00:18:43 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*line;
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
	expected = "teste 1 test 2 teste 5";

	write_to_stdin("teste 1 test 2 teste 5\nasdasdas dadsa sdas ds");
	line = get_cmd_line("> ");
	mu_assert_string_eq(expected, line);
	free(line);

	write_to_stdin("\n\n\n\n");
	write_to_stdin("\nteste 1 test 2 teste 5\nasdasdas dadsa sdas ds");
	line = get_cmd_line("> ");
	mu_assert_string_eq(expected, line);
	free(line);

	line = get_cmd_line("> ");
	mu_assert_string_eq("asdasdas dadsa sdas ds", line);
	free(line);

	write_to_stdin(NULL);
	line = get_cmd_line("> ");
	mu_assert_string_eq(NULL, line);
	free(line);
}

MU_TEST(check_asp_tst)

{
	_bool = vf_clone_quote("\"teste\'\"");
	mu_check(_bool == true);

	_bool = vf_clone_quote("\'teste2\"\'");
	mu_check(_bool == true);

	_bool = vf_clone_quote("\'teste3\'\"");
	mu_check(_bool == false);

	_bool = vf_clone_quote("\'teste4\"\"");
	mu_check(_bool == false);

	_bool = vf_clone_quote("\"\'teste5\'");
	mu_check(_bool == false);
}

MU_TEST(check_cmd_path_tst)
{
	initalize_paths();

	line = get_cmd_path("cat");
	mu_check(line != NULL);
	free(line);

	line = get_cmd_path("grep");
	mu_check(line != NULL);
	free(line);

	line = get_cmd_path("luiz");
	mu_check(line == NULL);
	free(line);

	line = get_cmd_path(NULL);
	mu_check(line == NULL);
	free(line);

	//o access fala que existe um script, não sei c e certo.

	// line = get_cmd_path("");
	// mu_check(line == NULL);
	// free(line);

}

MU_TEST_SUITE(example_suite)
{
	MU_SUITE_CONFIGURE(&example_setup, &example_teardown);

	//MU_RUN_TEST(get_line_cmd_tst);
	//MU_RUN_TEST(check_asp_tst);
	MU_RUN_TEST(check_cmd_path_tst);
}

int	main(void)
{
	MU_RUN_SUITE(example_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
