/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 14:57:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	_current_path[PATH_MAX];

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
	mu_assert_int_eq(0, bi_cd((char *[]){"cd", "sources", NULL}));
	getcwd(_current_path, sizeof(_current_path));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));

	mu_assert_int_eq(0, bi_cd((char *[]){"cd", "..", NULL}));
	getcwd(_current_path, sizeof(_current_path));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));
}

MU_TEST(bad_path_tst)
{
	getcwd(_current_path, sizeof(_current_path));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "asdsad", NULL}));
	mu_assert_string_eq(_current_path, envht_get(PWD_KEY));

	mu_assert_int_eq(1, bi_cd((char *[]){"cd", "/asdsad", NULL}));
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
	MU_RUN_TEST(bad_path_tst);
	MU_RUN_TEST(too_many_args_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(cd_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
