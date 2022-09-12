/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 22:59:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

char	**_tokens;
t_parse_list	*_plist;
t_parse_list	*_expected;
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

MU_TEST(e_1_tst)
{
	_plist = parse((char *[]){"a", NULL});

	ft_dlst_add(&_expected, new_exec((char *[]){"a", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(e_2_tst)
{
	_plist = parse((char *[]){"ls", "-la", NULL});

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "-la", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(p_tst)
{
	_plist = parse((char *[]){"|", NULL});

	ft_dlst_add(&_expected, new_pipe());

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(r_tst)
{
	_plist = parse((char *[]){"<", "file", NULL});

	ft_dlst_add(&_expected, new_read_file("file"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(h_tst)
{
	_plist = parse((char *[]){"<<", "delimiter", NULL});

	ft_dlst_add(&_expected, new_heredoc("delimiter"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(t_tst)
{
	_plist = parse((char *[]){">", "file", NULL});

	ft_dlst_add(&_expected, new_truncate("file"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(a_tst)
{
	_plist = parse((char *[]){">>", "file", NULL});

	ft_dlst_add(&_expected, new_append("file"));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ep_tst)
{
	_tokens = (char *[]){
		"ls", "-la",
		"|", NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "-la", NULL}));
	ft_dlst_add(&_expected, new_pipe());

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

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "-la", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"grep", "Makefile", NULL}));
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

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "-la", "bar", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_truncate("output"));
	ft_dlst_add(&_expected, new_exec((char *[]){"grep", "main", NULL}));
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

	ft_dlst_add(&_expected, new_read_file("foo"));
	ft_dlst_add(&_expected, new_read_file("foo"));
	ft_dlst_add(&_expected, new_read_file("foo"));
	ft_dlst_add(&_expected, new_exec((char *[]){"grep", "g", "a", "r", "m", "o", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ep_ep_e_tst)
{
	_tokens = (char *[]){
		"cat",
		"|",

		"cat",
		"|",

		"ls",
		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec((char *[]){"cat", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"cat", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", NULL}));
	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(eaetep_ethp_trep_ep_tst)
{
	_tokens = (char *[]){
		"cat", "cat", "cat",
		">>", "file",
		"cat", "cat",
		">", "file",
		"cat", "cat",
		"|",

		"cat", "cat",
		">", "file",
		"<<", "delim",
		"|",

		">", "file",
		"<", "file",
		"cat", "cat", "cat", "cat", "cat", "cat", "cat", "cat",
		"|",

		"dog",
		"|",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_append("file"));
	ft_dlst_add(&_expected, new_truncate("file"));
	ft_dlst_add(&_expected, new_exec((char *[]){"cat", "cat", "cat", "cat", "cat", "cat", "cat", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_truncate("file"));
	ft_dlst_add(&_expected, new_heredoc("delim"));
	ft_dlst_add(&_expected, new_exec((char *[]){"cat", "cat", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_truncate("file"));
	ft_dlst_add(&_expected, new_read_file("file"));
	ft_dlst_add(&_expected, new_exec((char *[]){"cat", "cat", "cat", "cat", "cat", "cat", "cat", "cat", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"dog", NULL}));
	ft_dlst_add(&_expected, new_pipe());

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

	ft_dlst_add(&_expected, new_read_file("foo"));
	ft_dlst_add(&_expected, new_read_file("grep"));
	ft_dlst_add(&_expected, new_read_file("foo"));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "ls", "ls", "ls", "ls", NULL}));
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

	ft_dlst_add(&_expected, new_read_file("foo"));
	ft_dlst_add(&_expected, new_heredoc("foo"));
	ft_dlst_add(&_expected, new_truncate("foo"));
	ft_dlst_add(&_expected, new_append("foo"));
	ft_dlst_add(&_expected, new_exec((char *[]){"grep", "a", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", NULL}));
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

	ft_dlst_add(&_expected, new_read_file("tr"));
	ft_dlst_add(&_expected, new_exec((char *[]){"infile", "a", "'   '", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_truncate("outfile"));
	ft_dlst_add(&_expected, new_exec((char *[]){"tr", "' '", "x", NULL}));

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

	ft_dlst_add(&_expected, new_heredoc("README.md"));
	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "-l", "-a", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_append("file"));
	ft_dlst_add(&_expected, new_exec((char *[]){"grep", "read", NULL}));

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

	ft_dlst_add(&_expected, new_read_file("tr"));
	ft_dlst_add(&_expected, new_exec((char *[]){"infile", "a", "\'  \"   \'", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"tr", "\' \"      x > outfile", NULL}));
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

	ft_dlst_add(&_expected, new_read_file("file"));
	ft_dlst_add(&_expected, new_truncate("file"));
	ft_dlst_add(&_expected, new_exec((char *[]){"make", "all", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_heredoc("delim"));
	ft_dlst_add(&_expected, new_append("file"));
	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "-l", "-la", "/", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_heredoc("delim"));
	ft_dlst_add(&_expected, new_heredoc("delim"));
	ft_dlst_add(&_expected, new_heredoc("delim"));
	ft_dlst_add(&_expected, new_exec((char *[]){"ls", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_append("file"));
	ft_dlst_add(&_expected, new_truncate("file"));
	ft_dlst_add(&_expected, new_exec((char *[]){"grep", "a", "b", "c", "d", "e", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ep_2_tst)
{
	_tokens = (char *[]){
		"ls", "-la", "..",
		"|",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "-la", "..", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ep_ep_e_2_tst)
{
	_tokens = (char *[]){
		"ls", "-la", "..",
		"|",

		"cat", "-e",
		"|",

		"wc", "-l",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_exec((char *[]){"ls", "-la", "..", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"cat", "-e", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_exec((char *[]){"wc", "-l", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(erp_et_tst)
{
	_tokens = (char *[]){
		"infile",
		"<", "tr",
		"a", "\"   \"",
		"|",

		"tr",
		">", "outfile",
		"\" \"", "x",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file("tr"));
	ft_dlst_add(&_expected, new_exec((char *[]){"infile", "a", "\"   \"", NULL}));
	ft_dlst_add(&_expected, new_pipe());

	ft_dlst_add(&_expected, new_truncate("outfile"));
	ft_dlst_add(&_expected, new_exec((char *[]){"tr", "\" \"", "x", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(eret_tst)
{
	_tokens = (char *[]){
		"infile",
		"<", "tr",
		"a", "\'  \"   \' |   tr \' \"     \'", "x",
		">", "outfile",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file("tr"));
	ft_dlst_add(&_expected, new_truncate("outfile"));
	ft_dlst_add(&_expected, new_exec((char *[]){"infile", "a", "\'  \"   \' |   tr \' \"     \'", "x", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ere_tst)
{
	_tokens = (char *[]){
		"infile",
		"<", "tr",
		"a", "\'  \"   \' |   tr \' \"      x > outfile",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file("tr"));
	ft_dlst_add(&_expected, new_exec((char *[]){"infile", "a", "\'  \"   \' |   tr \' \"      x > outfile", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(re_tst)
{
	_tokens = (char *[]){
		"<", "out", "rg", "'.'",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_read_file("out"));
	ft_dlst_add(&_expected, new_exec((char *[]){"rg", "'.'", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ea_tst)
{
	_tokens = (char *[]){
		"rg", "a", ">>", "out",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_append("out"));
	ft_dlst_add(&_expected, new_exec((char *[]){"rg", "a", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(he_tst)
{
	_tokens = (char *[]){
		"<<", ".", "cat",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_heredoc("."));
	ft_dlst_add(&_expected, new_exec((char *[]){"cat", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(eh_tst)
{
	_tokens = (char *[]){
		"cat", "<<", ".",

		NULL};
	_plist = parse(_tokens);

	ft_dlst_add(&_expected, new_heredoc("."));
	ft_dlst_add(&_expected, new_exec((char *[]){"cat", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(et_null_tst)
{
	_plist = parse((char *[]){"a", ">", NULL});

	ft_dlst_add(&_expected, new_truncate(NULL));
	ft_dlst_add(&_expected, new_exec((char *[]){"a", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(ea_null_tst)
{
	_plist = parse((char *[]){"a", ">>", NULL});

	ft_dlst_add(&_expected, new_append(NULL));
	ft_dlst_add(&_expected, new_exec((char *[]){"a", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(er_null_tst)
{
	_plist = parse((char *[]){"a", "<", NULL});

	ft_dlst_add(&_expected, new_read_file(NULL));
	ft_dlst_add(&_expected, new_exec((char *[]){"a", NULL}));

	assert_dlist_equivalent(_expected, _plist, compare_pnode);

	destroy_plists();
}

MU_TEST(eh_null_tst)
{
	_plist = parse((char *[]){"a", "<<", NULL});

	ft_dlst_add(&_expected, new_heredoc(NULL));
	ft_dlst_add(&_expected, new_exec((char *[]){"a", NULL}));

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

	MU_RUN_TEST(e_1_tst);
	MU_RUN_TEST(e_2_tst);
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

	MU_RUN_TEST(ep_ep_e_tst);

	MU_RUN_TEST(retp_heap_hehhp_ate_tst);
	MU_RUN_TEST(eaetep_ethp_trep_ep_tst);

	MU_RUN_TEST(ep_2_tst);
	MU_RUN_TEST(ep_ep_e_2_tst);
	MU_RUN_TEST(erp_et_tst);
	MU_RUN_TEST(eret_tst);
	MU_RUN_TEST(ere_tst);
	MU_RUN_TEST(re_tst);
	MU_RUN_TEST(ea_tst);
	MU_RUN_TEST(he_tst);
	MU_RUN_TEST(eh_tst);

	MU_RUN_TEST(et_null_tst);
	MU_RUN_TEST(ea_null_tst);
	MU_RUN_TEST(er_null_tst);
	MU_RUN_TEST(eh_null_tst);

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
