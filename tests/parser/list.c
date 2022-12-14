/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 20:10:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

t_parse_list	*_plist;

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(destroy_tst)
{
	_plist = NULL;

	ft_dlst_add(&_plist, new_exec((char *[]){"ls", "-la", NULL}));
	ft_dlst_add(&_plist, new_pipe());
	ft_dlst_add(&_plist, new_exec((char *[]){"grep", "Makefile", NULL}));

	destroy_parse_list(&_plist);
	mu_check(NULL == _plist);
}

MU_TEST_SUITE(plist_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(destroy_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(plist_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
