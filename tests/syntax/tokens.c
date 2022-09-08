/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 15:42:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	**_tokens;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(semicolon_tst)
{
	_tokens = (char *[]){"firs;t", "secon\";\"d", NULL};
	mu_check(false == tokens_are_valid(_tokens));

	_tokens = (char *[]){"firs\';\'t", "secon\";\"d", NULL};
	mu_check(true == tokens_are_valid(_tokens));

	_tokens = (char *[]){"firs\';\'t", "secon\';\'d", NULL};
	mu_check(true == tokens_are_valid(_tokens));
}

MU_TEST_SUITE(tokens_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(semicolon_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(tokens_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
