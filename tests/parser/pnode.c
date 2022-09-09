/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnode.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 14:38:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_pnode	*_node;
void	*_empty;

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(new_tst)
{
	_node = new_pnode();
	mu_check(_node != NULL);

	_empty = ft_calloc(sizeof(t_pnode), 1);
	mu_check(0 == ft_memcmp(_node, _empty, sizeof(t_pnode)));
	mu_assert_int_eq(PT_NULL, _node->type);

	_node->file.fd = 42;
	mu_assert_int_eq(42, _node->file.fd);
	free(_node);
	free(_empty);
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);
	MU_RUN_TEST(new_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
