/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/24 16:11:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	_current_path[PATH_MAX];
char	_previous_path[PATH_MAX];

static void	test_cd(int expected_status, char **tokens)
{
	char	current_path[PATH_MAX];
	char	previous_path[PATH_MAX];

	getcwd(previous_path, sizeof(previous_path));
	mu_assert_int_eq(expected_status, bi_cd(tokens));
	getcwd(current_path, sizeof(current_path));
	mu_assert_string_eq(previous_path, envht_get(OLDPWD_KEY));
	mu_assert_string_eq(current_path, envht_get(PWD_KEY));
}

void	setup(void)
{
	mock_initialize_shell();
}
void	teardown(void)
{
	cleanup_shell();
}

MU_TEST(relative_tst)
{
	test_cd(0, (char *[]){"cd", "sources", NULL});
	test_cd(0, (char *[]){"cd", "..", NULL});
	test_cd(0, (char *[]){"cd", ".", NULL});
}

MU_TEST(absolute_tst)
{
	getcwd(_previous_path, sizeof(_previous_path));

	test_cd(0, (char *[]){"cd", "/home", NULL});
	test_cd(0, (char *[]){"cd", "/tmp", NULL});
	test_cd(0, (char *[]){"cd", _previous_path, NULL});

}

MU_TEST(no_args_tst)
{
	getcwd(_previous_path, sizeof(_previous_path));

	test_cd(0, (char *[]){"cd", NULL});
	getcwd(_current_path, sizeof(_current_path));
	mu_assert_string_eq(_current_path, envht_get("HOME"));

	test_cd(0, (char *[]){"cd", _previous_path, NULL});
}

MU_TEST(home_tst)
{
	getcwd(_previous_path, sizeof(_previous_path));

	test_cd(0, (char *[]){"cd", "~", NULL});
	getcwd(_current_path, sizeof(_current_path));
	mu_assert_string_eq(_current_path, envht_get("HOME"));

	test_cd(0, (char *[]){"cd", _previous_path, NULL});
}

MU_TEST(bad_path_tst)
{
	getcwd(_current_path, sizeof(_current_path));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "asdsad", NULL}));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "/asdsad", NULL}));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "main.c", NULL}));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));
}

MU_TEST(too_many_args_tst)
{
	getcwd(_current_path, sizeof(_current_path));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "sources", "adsada", NULL}));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "..", "dasdasda", NULL}));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "sources", "builtins", NULL}));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "sources", "builtins", NULL}));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));
}

MU_TEST_SUITE(cd_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(relative_tst);
	MU_RUN_TEST(absolute_tst);

	MU_RUN_TEST(no_args_tst);

	MU_RUN_TEST(bad_path_tst);
	MU_RUN_TEST(too_many_args_tst);

	// OPTIONAL
	// MU_RUN_TEST(home_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(cd_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
