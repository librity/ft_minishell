/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 14:40:17 by lpaulo-m         ###   ########.fr       */
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

MU_TEST_SUITE(control_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(singleton_tst);
}

int main(int argc, char **argv, char **envp)
{
	MU_DIVIDER;
	MU_RUN_SUITE(control_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
