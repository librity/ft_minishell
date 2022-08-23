/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/23 18:38:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char *raw_input;
char **expected;

static void assert_strarr_eq(char **_expected, char **_result)
{
	int i;

	i = 0;
	while (i < (int)ft_strarr_size(_expected))
	{
		mu_assert_string_eq(_expected[i], _result[i]);
		i++;
	}
}

static void test_tokens(char **_expected, char *_raw_input)
{
	char **tokens = tokenize(_raw_input);

	assert_strarr_eq(_expected, tokens);
}

static void lexer_setup(void)
{
}
static void lexer_teardown(void)
{
}

MU_TEST(simple_tokens)
{
	raw_input = "ls -la ..";
	expected = (char *[]){"ls", "-la", "..", NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(squoutes_tokens)
{
	raw_input = "infile   < tr a '   ' |   tr ' ' x > outfile";
	expected = (char *[]){
		"infile", "<",
		"tr", "a", "'   '", "|",
		"tr", "' '", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(dquoutes_tokens)
{
	raw_input = "infile   < tr a \"   \" |   tr \" \" x > outfile";
	expected = (char *[]){
		"infile", "<",
		"tr", "a", "\"   \"", "|",
		"tr", "\" \"", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(mixed_quoutes_tokens)
{
	raw_input = "infile   < tr a \"   \" |   tr \' \' x > outfile";
	expected = (char *[]){
		"infile", "<",
		"tr", "a", "\"   \"", "|",
		"tr", "\' \'", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(nested_quoute_tokens)
{
	raw_input = "infile   < tr a \"   \' |   tr \' \" x > outfile";
	expected = (char *[]){
		"infile", "<",
		"tr", "a", "\"   \' |   tr \' \"", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(char_quoute_tokens)
{
	raw_input = ".gitignore < tr ex ' X' | tr pi 'P ' > outfile";
	expected = (char *[]){
		".gitignore", "<",
		"tr", "ex", "' X'", "|",
		"tr", "pi", "'P '", ">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(inception_quoute_tokens)
{
	raw_input = "infile   < tr a   \'  \"   \' |   tr \' \"     \' x > outfile";
	expected = (char *[]){
		"infile", "<",
		"tr", "a", "\'  \"   \'", "|",
		"tr", "\' \"     \'", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(bad_quoute_tokens)
{
	raw_input = "infile   < tr a   \'  \"   \' |   tr \' \"      x > outfile";
	expected = (char *[]){
		"infile", "<",
		"tr", "a", "\'  \"   \'", "|",
		"tr", "\' \"      x > outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(lonely_quoute_tokens)
{
	raw_input = "inf'ile";
	expected = (char *[]){
		"inf'ile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(variable_tokens)
{
	raw_input = "MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; ./minshell";
	expected = (char *[]){
		"MAKE_PATH=./libs/libft", ";",
		"cd", "..", ";",
		"ls", "&&", "make", "-C", "$MAKE_PATH", ";",
		"./minshell",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(pipe_tokens)
{
	raw_input = "ls -la .. | cat -e | wc -l";
	expected = (char *[]){
		"ls", "-la", "..", "|",
		"cat", "-e", "|",
		"wc", "-l",
		NULL};
	test_tokens(expected, raw_input);

	raw_input = "          help| rg unset        ";
	expected = (char *[]){"help", "|", "rg", "unset", NULL};
	test_tokens(expected, raw_input);

	raw_input = "      help |rg unset        ";
	expected = (char *[]){"help", "|", "rg", "unset", NULL};
	test_tokens(expected, raw_input);

	raw_input = "help|rg unset";
	expected = (char *[]){"help", "|", "rg", "unset", NULL};
	test_tokens(expected, raw_input);

	raw_input = "|help|rg unset";
	expected = (char *[]){"|", "help", "|", "rg", "unset", NULL};
	test_tokens(expected, raw_input);

	raw_input = "|help|rg unset|";
	expected = (char *[]){"|", "help", "|", "rg", "unset", "|", NULL};
	test_tokens(expected, raw_input);
}

MU_TEST(truncate_tokens)
{
	raw_input = "     ls >out";
	expected = (char *[]){"ls", ">", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = "     ls> out";
	expected = (char *[]){"ls", ">", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = "      ls>out      ";
	expected = (char *[]){"ls", ">", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = ">ls>out      ";
	expected = (char *[]){">", "ls", ">", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = ">ls>out>";
	expected = (char *[]){">", "ls", ">", "out", ">", NULL};
	test_tokens(expected, raw_input);
}

MU_TEST(append_tokens)
{
	raw_input = "rg a >>out";
	expected = (char *[]){"rg", "a", ">>", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = "rg a>> out";
	expected = (char *[]){"rg", "a", ">>", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = "rg a>>out";
	expected = (char *[]){"rg", "a", ">>", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = ">>rg a>>out";
	expected = (char *[]){">>", "rg", "a", ">>", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = "rg a>>out>>";
	expected = (char *[]){"rg", "a", ">>", "out", ">>", NULL};
	test_tokens(expected, raw_input);
}

MU_TEST(infile_tokens)
{
	raw_input = "out<rg .";
	expected = (char *[]){"out", "<", "rg", ".", NULL};
	test_tokens(expected, raw_input);

	raw_input = "cat<out";
	expected = (char *[]){"cat", "<", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = "<cat out";
	expected = (char *[]){"<", "cat", "out", NULL};
	test_tokens(expected, raw_input);

	raw_input = "<out rg '.'";
	expected = (char *[]){"<", "out", "rg", "'.'", NULL};
	test_tokens(expected, raw_input);

	raw_input = "<out rg '.'<";
	expected = (char *[]){"<", "out", "rg", "'.'", "<", NULL};
	test_tokens(expected, raw_input);
}

MU_TEST(heredoc_tokens)
{
	raw_input = "<<. cat";
	expected = (char *[]){"<<", ".", "cat", NULL};
	test_tokens(expected, raw_input);

	raw_input = "cat<<.";
	expected = (char *[]){"cat", "<<", ".", NULL};
	test_tokens(expected, raw_input);
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

	// MU_RUN_TEST(infile_tokens);
	// MU_RUN_TEST(heredoc_tokens);
}

int main(void)
{
	MU_RUN_SUITE(lexer_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
