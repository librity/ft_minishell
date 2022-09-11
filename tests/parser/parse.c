/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 18:19:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

char	**_tokens;
t_parse_list	*_plist;
t_parse_list	*_expected;
t_parse_list	*_next;
t_parse	*_pnode;

void	setup(void)
{
}
void	teardown(void)
{
}

static void destroy_plists(void)
{
	destroy_parse_list(&_plist);
	destroy_parse_list(&_expected);
}

MU_TEST(e_tst)
{
	_plist = parse((char *[]){"ls", "-la", NULL});

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", "-la", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(p_tst)
{
	_plist = parse((char *[]){"|", NULL});

	ft_dlst_add(&_expected, new_pipe_parse());

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(r_tst)
{
	_plist = parse((char *[]){"<", "file", NULL});

	ft_dlst_add(&_expected, new_read_file_parse("file"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(h_tst)
{
	_plist = parse((char *[]){"<<", "delimiter", NULL});

	ft_dlst_add(&_expected, new_heredoc_parse("delimiter"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(t_tst)
{
	_plist = parse((char *[]){">", "file", NULL});

	ft_dlst_add(&_expected, new_truncate_parse("file"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(a_tst)
{
	_plist = parse((char *[]){">>", "file", NULL});

	ft_dlst_add(&_expected, new_append_parse("file"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ep_tst)
{
	_tokens = (char *[]){
		"ls", "-la",
		"|", NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", "-la", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ep_e_tst)
{
	_tokens = (char *[]){
		"ls", "-la",
		"|",
		"grep", "Makefile", NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", "-la", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"grep", "Makefile", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ep_et_tst)
{
	_tokens = (char *[]){
		"ls", "-la", "bar",
		"|",
		"grep", "main",
		">", "output", NULL };
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", "-la", "bar", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_truncate_parse("output"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"grep", "main", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(rrer_pe_tst)
{
	_tokens = (char *[]){
		"<", "foo",
		"<", "foo",
		"grep", "g", "a", "r", "m", "o",
		"<", "foo",
		"|",
		"ls", NULL };
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file_parse("foo"));
	ft_dlst_add(&_expected, new_read_file_parse("foo"));
	ft_dlst_add(&_expected, new_read_file_parse("foo"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"grep", "g", "a", "r", "m", "o", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(rrrp_e_tst)
{
	_tokens = (char *[]){
		"<", "foo",
		"<", "grep",
		"<", "foo",
		"|",
		"ls", "ls", "ls", "ls", "ls", NULL };
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file_parse("foo"));
	ft_dlst_add(&_expected, new_read_file_parse("grep"));
	ft_dlst_add(&_expected, new_read_file_parse("foo"));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", "ls", "ls", "ls", "ls", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(rhetap_e_tst)
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

	ft_dlst_add(&_expected, new_read_file_parse("foo"));
	ft_dlst_add(&_expected, new_heredoc_parse("foo"));
	ft_dlst_add(&_expected, new_truncate_parse("foo"));
	ft_dlst_add(&_expected, new_append_parse("foo"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"grep", "a", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(rep_te_tst)
{
	_tokens = (char *[]){
		"infile",
		"<", "tr",
		"a", "'   '",
		"|",

		"tr", "' '",
		">", "outfile",
		"x",
		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file_parse("tr"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"infile", "a", "'   '", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_truncate_parse("outfile"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"tr", "' '", "x", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(hep_ae_tst)
{
	_tokens = (char *[]){
		"ls", "<<", "README.md", "-l", "-a",
		"|",

		"grep", ">>", "file", "read",
		NULL };
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_heredoc_parse("README.md"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", "-l", "-a", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_append_parse("file"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"grep", "read", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(erep_e_tst)
{
	_tokens = (char *[]){
		"infile",
		"<", "tr",
		"a", "\'  \"   \'",
		"|",

		"tr", "\' \"      x > outfile",
		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file_parse("tr"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"infile", "a", "\'  \"   \'", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_exec_parse((char *[]){"tr", "\' \"      x > outfile", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(retp_heap_hehhp_ate_tst)
{
	_tokens = (char *[]){
		"<", "file",
		"make", "all",
		">", "file",
		"|",

		"<<", "delim",
		"ls", "-l", "-la", "/",
		">>", "file",
		"|",

		"<<", "delim",
		"ls",
		"<<", "delim",
		"<<", "delim",
		"|",

		">>", "file",
		">", "file",
		"grep", "a", "b", "c", "d", "e",
		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file_parse("file"));
	ft_dlst_add(&_expected, new_truncate_parse("file"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"make", "all", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_heredoc_parse("delim"));
	ft_dlst_add(&_expected, new_append_parse("file"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", "-l", "-la", "/", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_heredoc_parse("delim"));
	ft_dlst_add(&_expected, new_heredoc_parse("delim"));
	ft_dlst_add(&_expected, new_heredoc_parse("delim"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"ls", NULL}));
	ft_dlst_add(&_expected, new_pipe_parse());

	ft_dlst_add(&_expected, new_append_parse("file"));
	ft_dlst_add(&_expected, new_truncate_parse("file"));
	ft_dlst_add(&_expected, new_exec_parse((char *[]){"grep", "a", "b", "c", "d", "e", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(empty_tst)
{
	_plist = parse((char *[]){NULL});

	mu_check(NULL == _plist);
}

MU_TEST(null_tst)
{
	_plist = parse(NULL);

	mu_check(NULL == _plist);
}

MU_TEST_SUITE(parse_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(e_tst);
	MU_RUN_TEST(p_tst);
	MU_RUN_TEST(r_tst);
	MU_RUN_TEST(h_tst);
	MU_RUN_TEST(t_tst);
	MU_RUN_TEST(a_tst);

	MU_RUN_TEST(ep_tst);

	MU_RUN_TEST(ep_e_tst);
	MU_RUN_TEST(ep_et_tst);
	MU_RUN_TEST(rrer_pe_tst);
	MU_RUN_TEST(rrrp_e_tst);
	MU_RUN_TEST(rhetap_e_tst);
	MU_RUN_TEST(erep_e_tst);

	MU_RUN_TEST(rep_te_tst);
	MU_RUN_TEST(hep_ae_tst);

	MU_RUN_TEST(retp_heap_hehhp_ate_tst);

	MU_RUN_TEST(empty_tst);
	MU_RUN_TEST(null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(parse_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
