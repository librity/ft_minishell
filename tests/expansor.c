/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:14:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 17:46:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*value;

void	setup(void)
{
	c()->envp = (char *[]){NULL};
	initilize_envht();
}
void	teardown(void)
{
	destroy_envht();
}


MU_TEST(get_variable)
{
	mu_check(true == envht_insert("foo", "bar"));
	value = expand_str("foo");

	mu_assert_string_eq("bar", value);
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(get_variable);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
