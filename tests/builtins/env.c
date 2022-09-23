/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 14:04:01 by lpaulo-m         ###   ########.fr       */
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

MU_TEST(dump_tst)
{
	mu_check(true == bi_env((char *[]){"env", NULL}));
}

MU_TEST_SUITE(env_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(dump_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(env_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
