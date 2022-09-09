/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 15:07:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(starts_with_number_tst)
{
	mu_check(true == is_valid_variable("garmon"));
	mu_check(true == is_valid_variable("gar123mon"));
	mu_check(true == is_valid_variable("garmon123"));
	mu_check(true == is_valid_variable("gar9mon"));
	mu_check(true == is_valid_variable("garmon9"));

	mu_check(false == is_valid_variable("123garmon"));
	mu_check(false == is_valid_variable("1garmon"));
	mu_check(false == is_valid_variable("9garmon"));
	mu_check(false == is_valid_variable("2"));
}

MU_TEST(metacharacters_tst)
{
	mu_check(false == is_valid_variable("?garmon"));
	mu_check(false == is_valid_variable("garmon?"));
	mu_check(false == is_valid_variable("gar?mon"));

	mu_check(false == is_valid_variable("\'garmon"));
	mu_check(false == is_valid_variable("garmon\'"));
	mu_check(false == is_valid_variable("gar\'mon"));

	mu_check(false == is_valid_variable("\"garmon"));
	mu_check(false == is_valid_variable("garmon\""));
	mu_check(false == is_valid_variable("gar\"mon"));

	mu_check(false == is_valid_variable("\\garmon"));
	mu_check(false == is_valid_variable("garmon\\"));
	mu_check(false == is_valid_variable("gar\\mon"));

	mu_check(false == is_valid_variable("$garmon"));
	mu_check(false == is_valid_variable("garmon$"));
	mu_check(false == is_valid_variable("gar$mon"));

	mu_check(false == is_valid_variable("`garmon"));
	mu_check(false == is_valid_variable("garmon`"));
	mu_check(false == is_valid_variable("gar`mon"));

	mu_check(false == is_valid_variable("=garmon"));
	mu_check(false == is_valid_variable("garmon="));
	mu_check(false == is_valid_variable("gar=mon"));

	mu_check(false == is_valid_variable("*garmon"));
	mu_check(false == is_valid_variable("garmon*"));
	mu_check(false == is_valid_variable("gar*mon"));

	mu_check(false == is_valid_variable("@garmon"));
	mu_check(false == is_valid_variable("garmon@"));
	mu_check(false == is_valid_variable("gar@mon"));

	mu_check(false == is_valid_variable("~garmon"));
	mu_check(false == is_valid_variable("garmon~"));
	mu_check(false == is_valid_variable("gar~mon"));

	mu_check(false == is_valid_variable("<garmon"));
	mu_check(false == is_valid_variable("garmon<"));
	mu_check(false == is_valid_variable("gar<mon"));

	mu_check(false == is_valid_variable(">garmon"));
	mu_check(false == is_valid_variable("garmon>"));
	mu_check(false == is_valid_variable("gar>mon"));

	mu_check(false == is_valid_variable("(garmon"));
	mu_check(false == is_valid_variable("garmon("));
	mu_check(false == is_valid_variable("gar(mon"));

	mu_check(false == is_valid_variable(")garmon"));
	mu_check(false == is_valid_variable("garmon)"));
	mu_check(false == is_valid_variable("gar)mon"));

	mu_check(false == is_valid_variable("!garmon"));
	mu_check(false == is_valid_variable("garmon!"));
	mu_check(false == is_valid_variable("gar!mon"));

	mu_check(false == is_valid_variable("|garmon"));
	mu_check(false == is_valid_variable("garmon|"));
	mu_check(false == is_valid_variable("gar|mon"));

	mu_check(false == is_valid_variable("!garmon"));
	mu_check(false == is_valid_variable("garmon!"));
	mu_check(false == is_valid_variable("gar!mon"));

	mu_check(false == is_valid_variable("&garmon"));
	mu_check(false == is_valid_variable("garmon&"));
	mu_check(false == is_valid_variable("gar&mon"));

	mu_check(false == is_valid_variable(";garmon"));
	mu_check(false == is_valid_variable("garmon;"));
	mu_check(false == is_valid_variable("gar;mon"));

	mu_check(false == is_valid_variable(" garmon"));
	mu_check(false == is_valid_variable("garmon "));
	mu_check(false == is_valid_variable("gar mon"));

	mu_check(false == is_valid_variable("\ngarmon"));
	mu_check(false == is_valid_variable("garmon\n"));
	mu_check(false == is_valid_variable("gar\nmon"));

	mu_check(false == is_valid_variable("?"));
	mu_check(false == is_valid_variable("foo?"));
}

MU_TEST_SUITE(validator_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(starts_with_number_tst);

	MU_RUN_TEST(metacharacters_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(validator_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
