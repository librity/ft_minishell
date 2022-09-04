/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 15:09:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_minishell	*_control;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(singleton_tst)
{
	_control = c();
	mu_check(_control == c());
	mu_check(_control == c());
	mu_check(_control == c());
}

MU_TEST(static_tst)
{
	mu_check(false == c()->debug);
	mu_assert_int_eq(0, c()->argc);
	mu_check(NULL == c()->argv);
	mu_check(NULL == c()->envp);
}

MU_TEST(initialize_tst)
{
	initialize_control(42, (void *)42, (void *)42);

	mu_check(true == c()->debug);
	mu_assert_int_eq(42, c()->argc);
	mu_check((void *)42 == c()->argv);
	mu_check((void *)42 == c()->envp);

	ft_bzero(c(), sizeof(t_minishell));
}

MU_TEST(deinitialize_tst)
{
	initialize_control(42, (void *)42, (void *)42);
	deinitialize_control();

	mu_check(false == c()->debug);
	mu_assert_int_eq(0, c()->argc);
	mu_check(NULL == c()->argv);
	mu_check(NULL == c()->envp);
}

MU_TEST(deinitialize_tst)
{
	set_debug(true);
	mu_check(debug() == true);

	set_debug(false);
	mu_check(debug() == false);
}

MU_TEST_SUITE(control_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(singleton_tst);
	MU_RUN_TEST(static_tst);
	MU_RUN_TEST(initialize_tst);
	MU_RUN_TEST(deinitialize_tst);
}

int main(int argc, char **argv, char **envp)
{
	MU_DIVIDER;
	MU_RUN_SUITE(control_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
