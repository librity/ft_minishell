/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 16:19:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(valid_tst)
{
	mu_check(true == is_valid_filename("filename?"));
	mu_check(true == is_valid_filename("file\\name?"));
	mu_check(true == is_valid_filename("file\nname?"));
	mu_check(true == is_valid_filename("filename|"));

	mu_check(false == is_valid_filename("fil/ename?"));
}

MU_TEST(invalid_tst)
{
	mu_check(false == is_valid_filename("/filename"));
	mu_check(false == is_valid_filename("fil/ename"));
	mu_check(false == is_valid_filename("filename/"));
}

MU_TEST_SUITE(filename_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(valid_tst);
	MU_RUN_TEST(invalid_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(filename_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
