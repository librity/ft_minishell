/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/25 10:41:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parse_list	*_plist;

void	setup(void)
{
	mock_initialize_shell();
}
void	teardown(void)
{
	cleanup_shell();
}

MU_TEST(help_tst)
{
	_plist = NULL;

	ft_dlst_add(&_plist, new_exec((char *[]){"help", NULL}));

	execute(_plist);

	destroy_parse_list(&_plist);
}

MU_TEST_SUITE(pipeline_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(help_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pipeline_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
