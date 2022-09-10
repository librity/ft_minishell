/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/10 12:39:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

char	**_tokens;
t_plist	*_plist;
t_plist	*_expected;
t_plist	*_next;
t_pnode	*_pnode;

void	setup(void)
{
}
void	teardown(void)
{
}

// static void destroy_plists(void)
// {
// 	destroy_plist(&_plist);
// 	destroy_plist(&_expected);
// }

MU_TEST(e_tst)
{
	_plist = parse((char *[]){"ls", "-la", NULL});

	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"ls", "-la", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plist(&_plist);
	destroy_plist(&_expected);
}

MU_TEST(ep_tst)
{
	_tokens = (char *[]){
		"ls", "-la",
		"|", NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"ls", "-la", NULL}));
	ft_dlst_add(&_expected, new_pipe_pnode());
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plist(&_plist);
	destroy_plist(&_expected);
}

MU_TEST(epe_tst)
{
	_tokens = (char *[]){
		"ls", "-la",
		"|",
		"grep", "Makefile", NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"ls", "-la", NULL}));
	ft_dlst_add(&_expected, new_pipe_pnode());
	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"grep", "Makefile", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plist(&_plist);
	destroy_plist(&_expected);
}

MU_TEST(epet_tst)
{
	_tokens = (char *[]){
		"ls", "-la", "bar",
		"|",
		"grep", "main",
		">", "output", NULL };
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"ls", "-la", "bar", NULL}));
	ft_dlst_add(&_expected, new_pipe_pnode());
	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"grep", "main", NULL}));
	ft_dlst_add(&_expected, new_truncate_pnode("output"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plist(&_plist);
	destroy_plist(&_expected);
}

MU_TEST(rrerpe_tst)
{
	_tokens = (char *[]){
		"<", "foo",
		"<", "foo",
		"grep", "g", "a", "r", "m", "o",
		"<", "foo",
		"|",
		"ls", NULL };
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file_pnode("foo"));
	ft_dlst_add(&_expected, new_read_file_pnode("foo"));
	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"grep", "g", "a", "r", "m", "o", NULL}));
	ft_dlst_add(&_expected, new_read_file_pnode("foo"));
	ft_dlst_add(&_expected, new_pipe_pnode());
	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"ls", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plist(&_plist);
	destroy_plist(&_expected);
}

MU_TEST(rrrpe_tst)
{
	_tokens = (char *[]){
		"<", "foo",
		"<", "grep",
		"<", "foo",
		"|",
		"ls", "ls", "ls", "ls", "ls", NULL };
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file_pnode("foo"));
	ft_dlst_add(&_expected, new_read_file_pnode("grep"));
	ft_dlst_add(&_expected, new_read_file_pnode("foo"));
	ft_dlst_add(&_expected, new_pipe_pnode());
	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"ls", "ls", "ls", "ls", "ls", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plist(&_plist);
	destroy_plist(&_expected);
}

MU_TEST(rhetape_tst)
{
	_tokens = (char *[]){
		"<", "foo",
		"<<", "foo",
		"grep", "a",
		">", "foo",
		">>", "foo",
		"|",
		"ls", NULL };
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file_pnode("foo"));
	ft_dlst_add(&_expected, new_heredoc_pnode("foo"));
	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"grep", "a", NULL}));
	ft_dlst_add(&_expected, new_truncate_pnode("foo"));
	ft_dlst_add(&_expected, new_append_pnode("foo"));
	ft_dlst_add(&_expected, new_pipe_pnode());
	ft_dlst_add(&_expected, new_exec_pnode((char *[]){"ls", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plist(&_plist);
	destroy_plist(&_expected);
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

	MU_RUN_TEST(e_tst);
	MU_RUN_TEST(ep_tst);
	MU_RUN_TEST(epe_tst);
	MU_RUN_TEST(epet_tst);
	MU_RUN_TEST(rrerpe_tst);
	MU_RUN_TEST(rrrpe_tst);
	MU_RUN_TEST(rhetape_tst);

	MU_RUN_TEST(destroy_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(plist_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
