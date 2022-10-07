/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 17:16:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

char **_tokens;
t_parse_list *_plist;
t_parse_list *_expected;
t_parse *_pnode;

void setup(void)
{
}
void teardown(void)
{
	free_lalloc();
}

MU_TEST(e_1_tst)
{
	_plist = parse((char *[]){"a", NULL});

	_expected = NULL;
	add_exec(&_expected, (char *[]){"a", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(e_2_tst)
{
	_plist = parse((char *[]){"ls", "-la", NULL});

	_expected = NULL;
	add_exec(&_expected, (char *[]){"ls", "-la", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(p_tst)
{
	_plist = parse((char *[]){"|", NULL});

	_expected = NULL;
	add_pipe(&_expected);

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(r_tst)
{
	_plist = parse((char *[]){"<", "file", NULL});

	_expected = NULL;
	add_read_file(&_expected, "file");

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(h_tst)
{
	_plist = parse((char *[]){"<<", "delimiter", NULL});

	_expected = NULL;
	add_heredoc(&_expected, "delimiter");

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(t_tst)
{
	_plist = parse((char *[]){">", "file", NULL});

	_expected = NULL;
	add_truncate(&_expected, "file");

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(a_tst)
{
	_plist = parse((char *[]){">>", "file", NULL});

	_expected = NULL;
	add_append(&_expected, "file");

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(ep_tst)
{
	_tokens = (char *[]){
		"ls", "-la",
		"|", NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_exec(&_expected, (char *[]){"ls", "-la", NULL});
	add_pipe(&_expected);

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(ep_e_tst)
{
	_tokens = (char *[]){
		"ls", "-la",
		"|",
		"grep", "Makefile", NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_exec(&_expected, (char *[]){"ls", "-la", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"grep", "Makefile", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(ep_et_tst)
{
	_tokens = (char *[]){
		"ls", "-la", "bar",
		"|",
		"grep", "main",
		">", "output", NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_exec(&_expected, (char *[]){"ls", "-la", "bar", NULL});
	add_pipe(&_expected);

	add_truncate(&_expected, "output");
	add_exec(&_expected, (char *[]){"grep", "main", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(rrer_pe_tst)
{
	_tokens = (char *[]){
		"<", "foo",
		"<", "foo",
		"grep", "g", "a", "r", "m", "o",
		"<", "foo",
		"|",
		"ls", NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_read_file(&_expected, "foo");
	add_read_file(&_expected, "foo");
	add_read_file(&_expected, "foo");
	add_exec(&_expected, (char *[]){"grep", "g", "a", "r", "m", "o", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"ls", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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

	_expected = NULL;
	add_exec(&_expected, (char *[]){"cat", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"cat", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"ls", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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

	_expected = NULL;
	add_append(&_expected, "file");
	add_truncate(&_expected, "file");
	add_exec(&_expected, (char *[]){"cat", "cat", "cat", "cat", "cat", "cat", "cat", NULL});
	add_pipe(&_expected);

	add_truncate(&_expected, "file");
	add_heredoc(&_expected, "delim");
	add_exec(&_expected, (char *[]){"cat", "cat", NULL});
	add_pipe(&_expected);

	add_truncate(&_expected, "file");
	add_read_file(&_expected, "file");
	add_exec(&_expected, (char *[]){"cat", "cat", "cat", "cat", "cat", "cat", "cat", "cat", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"dog", NULL});
	add_pipe(&_expected);

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(rrrp_e_tst)
{
	_tokens = (char *[]){
		"<", "foo",
		"<", "grep",
		"<", "foo",
		"|",
		"ls", "ls", "ls", "ls", "ls", NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_read_file(&_expected, "foo");
	add_read_file(&_expected, "grep");
	add_read_file(&_expected, "foo");
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"ls", "ls", "ls", "ls", "ls", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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
		"ls", NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_read_file(&_expected, "foo");
	add_heredoc(&_expected, "foo");
	add_truncate(&_expected, "foo");
	add_append(&_expected, "foo");
	add_exec(&_expected, (char *[]){"grep", "a", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"ls", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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

	_expected = NULL;
	add_read_file(&_expected, "tr");
	add_exec(&_expected, (char *[]){"infile", "a", "'   '", NULL});
	add_pipe(&_expected);

	add_truncate(&_expected, "outfile");
	add_exec(&_expected, (char *[]){"tr", "' '", "x", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(hep_ae_tst)
{
	_tokens = (char *[]){
		"ls", "<<", "README.md", "-l", "-a",
		"|",

		"grep", ">>", "file", "read",
		NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_heredoc(&_expected, "README.md");
	add_exec(&_expected, (char *[]){"ls", "-l", "-a", NULL});
	add_pipe(&_expected);

	add_append(&_expected, "file");
	add_exec(&_expected, (char *[]){"grep", "read", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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

	_expected = NULL;
	add_read_file(&_expected, "tr");
	add_exec(&_expected, (char *[]){"infile", "a", "\'  \"   \'", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"tr", "\' \"      x > outfile", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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

	_expected = NULL;
	add_read_file(&_expected, "file");
	add_truncate(&_expected, "file");
	add_exec(&_expected, (char *[]){"make", "all", NULL});
	add_pipe(&_expected);

	add_heredoc(&_expected, "delim");
	add_append(&_expected, "file");
	add_exec(&_expected, (char *[]){"ls", "-l", "-la", "/", NULL});
	add_pipe(&_expected);

	add_heredoc(&_expected, "delim");
	add_heredoc(&_expected, "delim");
	add_heredoc(&_expected, "delim");
	add_exec(&_expected, (char *[]){"ls", NULL});
	add_pipe(&_expected);

	add_append(&_expected, "file");
	add_truncate(&_expected, "file");
	add_exec(&_expected, (char *[]){"grep", "a", "b", "c", "d", "e", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(ep_2_tst)
{
	_tokens = (char *[]){
		"ls", "-la", "..",
		"|",

		NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_exec(&_expected, (char *[]){"ls", "-la", "..", NULL});
	add_pipe(&_expected);

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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

	_expected = NULL;
	add_exec(&_expected, (char *[]){"ls", "-la", "..", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"cat", "-e", NULL});
	add_pipe(&_expected);

	add_exec(&_expected, (char *[]){"wc", "-l", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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

	_expected = NULL;
	add_read_file(&_expected, "tr");
	add_exec(&_expected, (char *[]){"infile", "a", "\"   \"", NULL});
	add_pipe(&_expected);

	add_truncate(&_expected, "outfile");
	add_exec(&_expected, (char *[]){"tr", "\" \"", "x", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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

	_expected = NULL;
	add_read_file(&_expected, "tr");
	add_truncate(&_expected, "outfile");
	add_exec(&_expected, (char *[]){"infile", "a", "\'  \"   \' |   tr \' \"     \'", "x", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(ere_tst)
{
	_tokens = (char *[]){
		"infile",
		"<", "tr",
		"a", "\'  \"   \' |   tr \' \"      x > outfile",

		NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_read_file(&_expected, "tr");
	add_exec(&_expected, (char *[]){"infile", "a", "\'  \"   \' |   tr \' \"      x > outfile", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(re_tst)
{
	_tokens = (char *[]){
		"<", "out", "rg", "'.'",

		NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_read_file(&_expected, "out");
	add_exec(&_expected, (char *[]){"rg", "'.'", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(ea_tst)
{
	_tokens = (char *[]){
		"rg", "a", ">>", "out",

		NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_append(&_expected, "out");
	add_exec(&_expected, (char *[]){"rg", "a", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(he_tst)
{
	_tokens = (char *[]){
		"<<", ".", "cat",

		NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_heredoc(&_expected, ".");
	add_exec(&_expected, (char *[]){"cat", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(eh_tst)
{
	_tokens = (char *[]){
		"cat", "<<", ".",

		NULL};
	_plist = parse(_tokens);

	_expected = NULL;
	add_heredoc(&_expected, ".");
	add_exec(&_expected, (char *[]){"cat", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(et_null_tst)
{
	_plist = parse((char *[]){"a", ">", NULL});

	_expected = NULL;
	add_truncate(&_expected, NULL);
	add_exec(&_expected, (char *[]){"a", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(ea_null_tst)
{
	_plist = parse((char *[]){"a", ">>", NULL});

	_expected = NULL;
	add_append(&_expected, NULL);
	add_exec(&_expected, (char *[]){"a", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(er_null_tst)
{
	_plist = parse((char *[]){"a", "<", NULL});

	_expected = NULL;
	add_read_file(&_expected, NULL);
	add_exec(&_expected, (char *[]){"a", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
}

MU_TEST(eh_null_tst)
{
	_plist = parse((char *[]){"a", "<<", NULL});

	_expected = NULL;
	add_heredoc(&_expected, NULL);
	add_exec(&_expected, (char *[]){"a", NULL});

	assert_dlist_equivalent(_expected, _plist, compare_pnode);
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
