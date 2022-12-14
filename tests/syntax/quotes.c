/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 13:58:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(quotes_tst)
{
	mu_check(true == has_valid_quotes("\"valid\""));
	mu_check(true == has_valid_quotes("\'valid\'"));

	mu_check(true == has_valid_quotes("\"valid\'\""));
	mu_check(true == has_valid_quotes("\'valid\"\'"));

	mu_check(false == has_valid_quotes("\"ba\'d"));
	mu_check(false == has_valid_quotes("\'ba\"d"));

	mu_check(false == has_valid_quotes("\'bad\'\""));
	mu_check(false == has_valid_quotes("\'bad\"\""));
	mu_check(false == has_valid_quotes("\"bad\"\'"));
	mu_check(false == has_valid_quotes("\"bad\'\'"));

	mu_check(false == has_valid_quotes("\"\'bad\'"));
	mu_check(false == has_valid_quotes("\'\"bad\""));
	mu_check(false == has_valid_quotes("\'\"bad\""));
	mu_check(false == has_valid_quotes("\"\'bad\'"));
}

MU_TEST_SUITE(validator_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(quotes_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(validator_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
