/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/29 15:36:56 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	example_setup(void)
{
}
static void	example_teardown(void)
{
}

static void	write_to_stdin(char *string)
{
	pid_t	pid;
	int		pipe[2];

	pipe_or_die(pipe);
	pid = fork_or_die();
	if (pid == CHILD_PROCESS_ID)
	{
		str_to_pipe(pipe, string);
		exit(0);
	}
	pipe_to_stdin(pipe);
	close_pipe(pipe);
}

/**
 * TODO: Achar um jeito de poder passar uma string pro write pelo teste.
 */
MU_TEST(get_user_line_1)
{
	char	*user_line;

	write_to_stdin("OIE\n");
	user_line = get_user_line();
	mu_assert_string_eq("OIE", user_line);
}

MU_TEST(get_user_line_2)
{
	char	*user_line;

	write_to_stdin("tchal\n");
	user_line = get_user_line();
	mu_assert_string_eq("tchal", user_line);
}

MU_TEST(get_user_line_3)
{
	char	*user_line;

	write_to_stdin("oie\n");
	mu_assert_string_eq("oie", get_user_line());
	write_to_stdin("tchal\n");
	mu_assert_string_eq("tchal", get_user_line());
}

MU_TEST(get_user_line_4)
{
	char	*user_line;

	write_to_stdin("oie\n");
	write_to_stdin("tchal\n");
	mu_assert_string_eq("tchal", get_user_line());
}

MU_TEST(line_cmd_1)
{
	char	*result;
	char	*expected;

	expected = "This is a command";
	set_line_cmd("This is a command");
	result = line_cmd();
	mu_assert_string_eq(expected, result);
}

MU_TEST(verific_asp_line_cmd_1)
{
	mu_assert(verific_asp_line_cmd(" \'dsadasdasd \"\"\"\' ") == true, "Has valid quotes.");
}

MU_TEST(verific_asp_line_cmd_2)
{
	mu_assert(verific_asp_line_cmd(" \'dsadasdasd \"\"\"\'\" ") == false, "Does notHas valid quotes.");
}

MU_TEST_SUITE(example_suite)
{
	MU_SUITE_CONFIGURE(&example_setup, &example_teardown);
	MU_RUN_TEST(get_user_line_1);
	MU_RUN_TEST(get_user_line_2);
	MU_RUN_TEST(get_user_line_3);

	MU_RUN_TEST(verific_asp_line_cmd_1);
	MU_RUN_TEST(verific_asp_line_cmd_2);
	MU_RUN_TEST(line_cmd_1);
}

int	main(void)
{
	MU_RUN_SUITE(example_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
