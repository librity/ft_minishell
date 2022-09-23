/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 14:06:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void	setup(void)
{
	mock_initialize_shell();
}
void	teardown(void)
{
	cleanup_shell();
}

MU_TEST(trivial_tst)
{
	char	current_path[PATH_MAX];

	mu_check(true == bi_cd((char *[]){"cd", "sources", NULL}));
	getcwd(current_path, sizeof(current_path));
	mu_assert_string_eq(current_path, envht_get(PWD_KEY));

	mu_check(true == bi_cd((char *[]){"cd", "..", NULL}));
	getcwd(current_path, sizeof(current_path));
	mu_assert_string_eq(current_path, envht_get(PWD_KEY));

	mu_check(false == bi_cd((char *[]){"cd", "asdsad", NULL}));
	getcwd(current_path, sizeof(current_path));
	mu_assert_string_eq(current_path, envht_get(PWD_KEY));

	mu_check(false == bi_cd((char *[]){"cd", "sources", "builtins", NULL}));
	getcwd(current_path, sizeof(current_path));
	mu_assert_string_eq(current_path, envht_get(PWD_KEY));
}

MU_TEST_SUITE(cd_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(trivial_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(cd_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
