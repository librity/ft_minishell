/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 17:30:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	**_tokens;
t_plist	*_plist;
t_pnode	*_pnode;

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(exec_tst)
{
	_tokens = (char *[]){"ls", "-la", NULL};
	_plist = parse(_tokens);

	mu_check(NULL != _plist);
	mu_check(NULL != _plist->content);
	mu_check(NULL == _plist->next);

	_pnode = _plist->content;
	mu_assert_int_eq(PT_EXEC, _pnode->type);
	mu_assert_string_eq("ls", _pnode->exec.cmd);
	assert_strarr_eq(_tokens, _pnode->exec.tokens);

	destroy_plist(&_plist);
}

MU_TEST(exec_pipe_exec_tst)
{
	_tokens = (char *[]){"ls", "-la", "|", "grep", "Makefile", NULL};
	_plist = parse(_tokens);

	mu_check(NULL != _plist);
	mu_check(NULL != _plist->content);

	_pnode = _plist->content;
	mu_assert_int_eq(PT_EXEC, _pnode->type);
	mu_assert_string_eq("ls", _pnode->exec.cmd);
	assert_strarr_eq((char *[]){"ls", "-la", NULL}, _pnode->exec.tokens);

	mu_check(NULL != _plist->next);
	_pnode = _plist->next->content;
	mu_assert_int_eq(PT_PIPE, _pnode->type);

	mu_check(NULL != _plist->next->next);
	_pnode = _plist->next->next->content;
	mu_assert_int_eq(PT_EXEC, _pnode->type);
	mu_assert_string_eq("grep", _pnode->exec.cmd);
	assert_strarr_eq((char *[]){"grep", "Makefile", NULL}, _pnode->exec.tokens);

	mu_check(NULL == _plist->next->next->next);

	destroy_plist(&_plist);
}

MU_TEST(destroy_tst)
{
	_plist = NULL;

	ft_dlst_add(&_plist, new_exec_pnode((char *[]){"ls", "-la", NULL}));
	ft_dlst_add(&_plist, new_pipe_pnode());
	ft_dlst_add(&_plist, new_exec_pnode((char *[]){"grep", "Makefile", NULL}));

	destroy_plist(&_plist);
	mu_check(NULL == _plist);
}

MU_TEST_SUITE(plist_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(exec_tst);
	MU_RUN_TEST(exec_pipe_exec_tst);

	MU_RUN_TEST(destroy_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(plist_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
