/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 19:06:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char *_raw_input;
char **_expected;

static void test_tokens(char **_expected, char *_raw_input)
{
	char **tokens = tokenize(_raw_input);

	assert_strarr_eq(_expected, tokens);
	ft_free_strarr(tokens);
}

static void lexer_setup(void)
{
}
static void lexer_teardown(void)
{
}

MU_TEST(simple_tokens)
{
	_raw_input = "ls -la ..";
	_expected = (char *[]){"ls", "-la", "..", NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(squoutes_tokens)
{
	_raw_input = "infile   < tr a '   ' |   tr ' ' x > outfile";
	_expected = (char *[]){
		"infile", "<",
		"tr", "a", "'   '", "|",
		"tr", "' '", "x",
		">", "outfile",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(dquoutes_tokens)
{
	_raw_input = "infile   < tr a \"   \" |   tr \" \" x > outfile";
	_expected = (char *[]){
		"infile", "<",
		"tr", "a", "\"   \"", "|",
		"tr", "\" \"", "x",
		">", "outfile",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(mixed_quoutes_tokens)
{
	_raw_input = "infile   < tr a \"   \" |   tr \' \' x > outfile";
	_expected = (char *[]){
		"infile", "<",
		"tr", "a", "\"   \"", "|",
		"tr", "\' \'", "x",
		">", "outfile",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(nested_quoute_tokens)
{
	_raw_input = "infile   < tr a \"   \' |   tr \' \" x > outfile";
	_expected = (char *[]){
		"infile", "<",
		"tr", "a", "\"   \' |   tr \' \"", "x",
		">", "outfile",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(char_quoute_tokens)
{
	_raw_input = ".gitignore < tr ex ' X' | tr pi 'P ' > outfile";
	_expected = (char *[]){
		".gitignore", "<",
		"tr", "ex", "' X'", "|",
		"tr", "pi", "'P '", ">", "outfile",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(inception_quoute_tokens)
{
	_raw_input = "infile   < tr a   \'  \"   \' |   tr \' \"     \' x > outfile";
	_expected = (char *[]){
		"infile", "<",
		"tr", "a", "\'  \"   \'", "|",
		"tr", "\' \"     \'", "x",
		">", "outfile",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(bad_quoute_tokens)
{
	_raw_input = "infile   < tr a   \'  \"   \' |   tr \' \"      x > outfile";
	_expected = (char *[]){
		"infile", "<",
		"tr", "a", "\'  \"   \'", "|",
		"tr", "\' \"      x > outfile",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(lonely_quoute_tokens)
{
	_raw_input = "inf'ile";
	_expected = (char *[]){
		"inf'ile",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(variable_tokens)
{
	_raw_input = "MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; ./minshell";
	_expected = (char *[]){
		"MAKE_PATH=./libs/libft", ";",
		"cd", "..", ";",
		"ls", "&&", "make", "-C", "$MAKE_PATH", ";",
		"./minshell",
		NULL};

	test_tokens(_expected, _raw_input);
}

MU_TEST(pipe_tokens)
{
	_raw_input = "ls -la .. | cat -e | wc -l";
	_expected = (char *[]){
		"ls", "-la", "..", "|",
		"cat", "-e", "|",
		"wc", "-l",
		NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "          help| rg unset        ";
	_expected = (char *[]){"help", "|", "rg", "unset", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "      help |rg unset        ";
	_expected = (char *[]){"help", "|", "rg", "unset", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "help|rg unset";
	_expected = (char *[]){"help", "|", "rg", "unset", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "|help|rg unset";
	_expected = (char *[]){"|", "help", "|", "rg", "unset", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "|help|rg unset|";
	_expected = (char *[]){"|", "help", "|", "rg", "unset", "|", NULL};
	test_tokens(_expected, _raw_input);
}

MU_TEST(truncate_tokens)
{
	_raw_input = "     ls >out";
	_expected = (char *[]){"ls", ">", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "     ls> out";
	_expected = (char *[]){"ls", ">", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "      ls>out      ";
	_expected = (char *[]){"ls", ">", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = ">ls>out      ";
	_expected = (char *[]){">", "ls", ">", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = ">ls>out>";
	_expected = (char *[]){">", "ls", ">", "out", ">", NULL};
	test_tokens(_expected, _raw_input);
}

MU_TEST(append_tokens)
{
	_raw_input = "rg a >>out";
	_expected = (char *[]){"rg", "a", ">>", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "rg a>> out";
	_expected = (char *[]){"rg", "a", ">>", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "rg a>>out";
	_expected = (char *[]){"rg", "a", ">>", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = ">>rg a>>out";
	_expected = (char *[]){">>", "rg", "a", ">>", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "rg a>>out>>";
	_expected = (char *[]){"rg", "a", ">>", "out", ">>", NULL};
	test_tokens(_expected, _raw_input);
}

MU_TEST(infile_tokens)
{
	_raw_input = "out<rg .";
	_expected = (char *[]){"out", "<", "rg", ".", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "cat<out";
	_expected = (char *[]){"cat", "<", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "<cat out";
	_expected = (char *[]){"<", "cat", "out", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "<out rg '.'";
	_expected = (char *[]){"<", "out", "rg", "'.'", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "<out rg '.'<";
	_expected = (char *[]){"<", "out", "rg", "'.'", "<", NULL};
	test_tokens(_expected, _raw_input);
}

MU_TEST(heredoc_tokens)
{
	_raw_input = "<<. cat";
	_expected = (char *[]){"<<", ".", "cat", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "<<. cat<<";
	_expected = (char *[]){"<<", ".", "cat", "<<", NULL};
	test_tokens(_expected, _raw_input);

	_raw_input = "cat<<.";
	_expected = (char *[]){"cat", "<<", ".", NULL};
	test_tokens(_expected, _raw_input);
}

MU_TEST_SUITE(lexer_suite)
{
	MU_SUITE_CONFIGURE(&lexer_setup, &lexer_teardown);

	MU_RUN_TEST(simple_tokens);

	MU_RUN_TEST(squoutes_tokens);
	MU_RUN_TEST(dquoutes_tokens);

	MU_RUN_TEST(mixed_quoutes_tokens);
	MU_RUN_TEST(nested_quoute_tokens);
	MU_RUN_TEST(char_quoute_tokens);
	MU_RUN_TEST(inception_quoute_tokens);
	MU_RUN_TEST(bad_quoute_tokens);
	MU_RUN_TEST(lonely_quoute_tokens);

	MU_RUN_TEST(variable_tokens);

	MU_RUN_TEST(pipe_tokens);

	MU_RUN_TEST(truncate_tokens);
	MU_RUN_TEST(append_tokens);

	MU_RUN_TEST(infile_tokens);
	MU_RUN_TEST(heredoc_tokens);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(lexer_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
