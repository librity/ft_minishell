/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/20 21:49:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include <fcntl.h>
#include <minishell.h>

void	assert_strarr_eq(char **expected, char **result)
{
	int i = 0;

	while (i < (int)ft_strarr_size(expected))
	{
		mu_assert_string_eq(expected[i], result[i]);
		i++;
	}
}

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(simple_lexer)
{
	char *raw_input = "ls -la ..";
	char *expected[] = {"ls", "-la", "..", NULL};
	char **tokens = lex_input(raw_input);

	assert_strarr_eq(expected, tokens);
}

// MU_TEST(pipes_lexer)
// {
// 	char *raw_input = "ls -la .. | cat -e | wc -l";
// 	char **tokens = lex_input(raw_input);

// 	mu_assert_string_eq("ls", tokens[0]);
// 	mu_assert_string_eq("-la", tokens[1]);
// 	mu_assert_string_eq("..", tokens[2]);
// 	mu_assert_string_eq("..", tokens[2]);
// 	mu_assert_string_eq(NULL, tokens[3]);
// }

MU_TEST_SUITE(test_suite_tokens)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);
	MU_RUN_TEST(simple_lexer);
}

int	main(void)
{
	MU_RUN_SUITE(test_suite_tokens);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
