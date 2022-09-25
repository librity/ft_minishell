/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/24 17:10:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(is_builtin_tst)
{
	mu_check(true == is_builtin("echo"));
	mu_check(true == is_builtin("cd"));
	mu_check(true == is_builtin("pwd"));
	mu_check(true == is_builtin("export"));
	mu_check(true == is_builtin("unset"));
	mu_check(true == is_builtin("env"));
	mu_check(true == is_builtin("exit"));
	mu_check(true == is_builtin("help"));

	mu_check(false == is_builtin("a"));
	mu_check(false == is_builtin("b"));
	mu_check(false == is_builtin("teste"));
	mu_check(false == is_builtin("ls"));
	mu_check(false == is_builtin("./minishell"));
}

MU_TEST_SUITE(core_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(is_builtin_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(core_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
