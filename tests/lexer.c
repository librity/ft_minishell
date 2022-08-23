/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/23 00:38:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void assert_strarr_eq(char **expected, char **result)
{
	int i;

	i = 0;
	while (i < (int)ft_strarr_size(expected))
	{
		mu_assert_string_eq(expected[i], result[i]);
		i++;
	}
}

static void test_tokens(char **expected, char *raw_input)
{
	char **tokens = tokenize(raw_input);

	assert_strarr_eq(expected, tokens);
}

static void lexer_setup(void)
{
}
static void lexer_teardown(void)
{
}

MU_TEST(simple_tokens)
{
	char *raw_input = "ls -la ..";
	char *expected[] = {"ls", "-la", "..", NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(pipes_tokens)
{
	char *raw_input = "ls -la .. | cat -e | wc -l";
	char *expected[] = {
		"ls", "-la", "..", "|",
		"cat", "-e", "|",
		"wc", "-l",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(squoutes_tokens)
{
	char *raw_input = "infile   < tr a '   ' |   tr ' ' x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "'   '", "|",
		"tr", "' '", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(dquoutes_tokens)
{
	char *raw_input = "infile   < tr a \"   \" |   tr \" \" x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "\"   \"", "|",
		"tr", "\" \"", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(mixed_quoutes_tokens)
{
	char *raw_input = "infile   < tr a \"   \" |   tr \' \' x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "\"   \"", "|",
		"tr", "\' \'", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(nested_quoute_tokens)
{
	char *raw_input = "infile   < tr a \"   \' |   tr \' \" x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "\"   \' |   tr \' \"", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}


MU_TEST(char_quoute_tokens)
{
	char *raw_input = ".gitignore < tr ex ' X' | tr pi 'P ' > outfile";
	char *expected[] = {
		".gitignore", "<",
		"tr", "ex", "' X'", "|",
		"tr", "pi", "'P '", ">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(inception_quoute_tokens)
{
	char *raw_input = "infile   < tr a   \'  \"   \' |   tr \' \"     \' x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "\'  \"   \'", "|",
		"tr", "\' \"     \'", "x",
		">", "outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(bad_quoute_tokens)
{
	char *raw_input = "infile   < tr a   \'  \"   \' |   tr \' \"      x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "\'  \"   \'", "|",
		"tr", "\' \"      x > outfile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(lonely_quoute_tokens)
{
	char *raw_input = "inf'ile";
	char *expected[] = {
		"inf'ile",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST(variable_tokens)
{
	char *raw_input = "MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; ./minshell";
	char *expected[] = {
		"MAKE_PATH=./libs/libft", ";",
		"cd", "..", ";",
		"ls", "&&", "make", "-C", "$MAKE_PATH", ";",
		"./minshell",
		NULL};

	test_tokens(expected, raw_input);
}

MU_TEST_SUITE(lexer_suite)
{
	MU_SUITE_CONFIGURE(&lexer_setup, &lexer_teardown);
	MU_RUN_TEST(simple_tokens);
	MU_RUN_TEST(pipes_tokens);
	MU_RUN_TEST(squoutes_tokens);
	MU_RUN_TEST(dquoutes_tokens);
	MU_RUN_TEST(mixed_quoutes_tokens);
	MU_RUN_TEST(nested_quoute_tokens);
	MU_RUN_TEST(char_quoute_tokens);
	MU_RUN_TEST(inception_quoute_tokens);
	MU_RUN_TEST(bad_quoute_tokens);
	MU_RUN_TEST(lonely_quoute_tokens);
	MU_RUN_TEST(variable_tokens);
}

int main(void)
{
	MU_RUN_SUITE(lexer_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
