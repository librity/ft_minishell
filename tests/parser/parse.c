/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 16:35:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	**_tokens;
t_dlist	*_list;
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
	_list = parse(_tokens);

	mu_check(NULL != _list);
	mu_check(NULL != _list->content);
	mu_check(NULL == _list->next);

	_pnode = _list->content;
	mu_assert_int_eq(PT_EXEC, _pnode->type);
	mu_assert_string_eq("ls", _pnode->exec.cmd);
	assert_strarr_eq(_tokens, _pnode->exec.tokens);
}

MU_TEST(exec_pipe_exec_tst)
{
	_tokens = (char *[]){"ls", "-la", "|", "grep", "Makefile", NULL};
	_list = parse(_tokens);

	mu_check(NULL != _list);
	mu_check(NULL != _list->content);

	_pnode = _list->content;
	mu_assert_int_eq(PT_EXEC, _pnode->type);
	mu_assert_string_eq("ls", _pnode->exec.cmd);
	assert_strarr_eq((char *[]){"ls", "-la", NULL}, _pnode->exec.tokens);

	mu_check(NULL != _list->next);
	_pnode = _list->next->content;
	mu_assert_int_eq(PT_PIPE, _pnode->type);

	mu_check(NULL != _list->next->next);
	_pnode = _list->next->next->content;
	mu_assert_int_eq(PT_EXEC, _pnode->type);
	mu_assert_string_eq("grep", _pnode->exec.cmd);
	assert_strarr_eq((char *[]){"grep", "Makefile", NULL}, _pnode->exec.tokens);

	mu_check(NULL == _list->next->next->next);
}

MU_TEST_SUITE(plist_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(exec_tst);
	// MU_RUN_TEST(exec_pipe_exec_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(plist_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
