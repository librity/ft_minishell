/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/20 23:32:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void assert_strarr_eq(char **expected, char **result)
{
	int i;

	i = 0;
	while (i < (int)ft_strarr_size(expected))
	{
		mu_assert_string_eq(expected[i], result[i]);
		i++;
	}
}

void lexer_setup(void)
{
}
void lexer_teardown(void)
{
}

MU_TEST(simple_tokens)
{
	char *raw_input = "ls -la ..";
	char *expected[] = {"ls", "-la", "..", NULL};
	char **tokens = lex_input(raw_input);

	assert_strarr_eq(expected, tokens);
}

MU_TEST(pipes_tokens)
{
	char *raw_input = "ls -la .. | cat -e | wc -l";
	char *expected[] = {
		"ls", "-la", "..", "|",
		"cat", "-e", "|",
		"wc", "-l",
		NULL};
	char **tokens = lex_input(raw_input);

	assert_strarr_eq(expected, tokens);
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
	char **tokens = lex_input(raw_input);

	assert_strarr_eq(expected, tokens);
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
	char **tokens = lex_input(raw_input);

	assert_strarr_eq(expected, tokens);
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
	char **tokens = lex_input(raw_input);

	assert_strarr_eq(expected, tokens);
}

MU_TEST(nested_quoute_tokens)
{
	char *raw_input = "infile   < tr a \"   \' |   tr \' \" x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "\"   \' |   tr \' \"", "x",
		">", "outfile",
		NULL};
	char **tokens = lex_input(raw_input);

	assert_strarr_eq(expected, tokens);
}

MU_TEST(inception_quoute_tokens)
{
	char *raw_input = "infile   < tr a   \'  \"   \' |   tr \' \"     \' x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "\'  \"   \' |   tr \' \"     \'", "x",
		">", "outfile",
		NULL};
	char **tokens = lex_input(raw_input);

	assert_strarr_eq(expected, tokens);
}

MU_TEST(bad_quoute_tokens)
{
	char *raw_input = "infile   < tr a   \'  \"   \' |   tr \' \"      x > outfile";
	char *expected[] = {
		"infile", "<",
		"tr", "a", "\'  \"   \' |   tr \' \"     \'", "x",
		">", "outfile",
		NULL};
	char **tokens = lex_input(raw_input);

	mu_assert(tokens == NULL, "Should return NULL when qoutes don't close.");
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
	MU_RUN_TEST(inception_quoute_tokens);
	MU_RUN_TEST(bad_quoute_tokens);
}

int main(void)
{
	MU_RUN_SUITE(lexer_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
