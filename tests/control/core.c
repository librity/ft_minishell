/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/10/10 20:08:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_minishell		*_control;
t_list			**_lalloc;

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
	mu_check(NULL == c()->lalloc);
	mu_check(NULL == c()->envht);
}

MU_TEST(initialize_tst)
{
	initialize_control(42, (void *)42, (void *)42);

	mu_check(false == c()->debug);
	mu_assert_int_eq(42, c()->argc);
	mu_check((void *)42 == c()->argv);
	mu_check((void *)42 == c()->envp);
	mu_check(NULL == c()->lalloc);
	mu_check(NULL == c()->envht);

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
	mu_check(NULL == c()->lalloc);
	mu_check(NULL == c()->envht);
}

MU_TEST(debug_tst)
{
	mu_check(debug() == false);

	enable_debug();
	mu_check(debug() == true);

	ft_bzero(c(), sizeof(t_minishell));
}

MU_TEST(arguments_tst)
{
	c()->argc = 42;
	mu_assert_int_eq(42, argc());

	c()->argv = (void *)42;
	mu_check((void *)42 == argv());

	c()->envp = (void *)42;
	mu_check((void *)42 == envp());

	ft_bzero(c(), sizeof(t_minishell));
}

MU_TEST(lalloc_tst)
{
	_lalloc = &(c()->lalloc);
	mu_check(_lalloc == lalloc());
	mu_check(_lalloc == lalloc());
	mu_check(_lalloc == lalloc());

	c()->lalloc = (void *)42;
	mu_check(*lalloc() == (void *)42);

	ft_bzero(c(), sizeof(t_minishell));
}

MU_TEST(free_lalloc_tst)
{
	int i = 42;
	while (i < 200)
		ft_lalloc(lalloc(), sizeof(int) * i++);

	free_lalloc();
}

MU_TEST_SUITE(control_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(singleton_tst);
	MU_RUN_TEST(static_tst);

	MU_RUN_TEST(initialize_tst);
	MU_RUN_TEST(deinitialize_tst);

	MU_RUN_TEST(debug_tst);

	MU_RUN_TEST(arguments_tst);

	MU_RUN_TEST(lalloc_tst);
	MU_RUN_TEST(free_lalloc_tst);
}

int main(int argc, char **argv, char **envp)
{
	MU_DIVIDER;
	MU_RUN_SUITE(control_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
