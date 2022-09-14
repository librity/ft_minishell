/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/14 14:58:32 by lpaulo-m         ###   ########.fr       */
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
	mu_check(true == cd((char *[]){"cd", "sources", NULL}));
	mu_assert_string_eq("/home/lgeniole/code/ft/minishell/sources", envht_get(PWD_KEY));

	mu_check(true == cd((char *[]){"cd", "..", NULL}));
	mu_assert_string_eq("/home/lgeniole/code/ft/minishell", envht_get(PWD_KEY));

	mu_check(false == cd((char *[]){"cd", "asdsad", NULL}));
	mu_assert_string_eq("/home/lgeniole/code/ft/minishell", envht_get(PWD_KEY));
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
