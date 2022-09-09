/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 01:06:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static void	test_trim_tokens(char **expected, char **tokens)
{
	char	**trim_me;

	trim_me = ft_strarr_dup(tokens);
	trim_tokens(trim_me);
	assert_strarr_eq(expected, trim_me);
	ft_free_strarr(trim_me);
}

void test_setup(void)
{
}
void test_teardown(void)
{
}

MU_TEST(stress_tst)
{
	char **_tokens = (char *[]){
		"\'main\'", "ma\'in\'", "\'ma\'in", "m\'ai\'n", "\'main", "ma\'in", "main\'",
		"\'m\'ai\'n", "m\'ai\'n\'", "m\'a\'i\'n\'",
		"\"main\"", "ma\"in\"", "\"ma\"in", "m\"ai\"n", "\"main", "ma\"in", "main\"",
		"\"m\"ai\"n", "m\"ai\"n\"", "m\"a\"i\"n\"",
		"\"m\'ai\"n", "\'m\"ai\'n", "\'main\"", "ma\'in\"", "\'ma\"in", "m\'ai\"n",
		"\"main\'", "ma\"in\'", "\"ma\'in", "m\"ai\'n", "m\"a\'i\'n\"", "m\'a\"i\"n\'",
		"m\'a\'\"\'i\"n\'n", "m\"a\"\'\"i\'n\"n", "m\'a\"\"\'i\"n\'n" ,"m\"a\'\'\"i\'n\"n",
		"\"\'\'\'\'\'\'\"", "\'\"\"\"\"\"\"\'",
		NULL};

	char **_expected = (char *[]){
		"main", "main", "main", "main", "main", "main", "main",
		"main", "main", "main",
		"main", "main", "main", "main", "main", "main", "main",
		"main", "main", "main",
		"m\'ain", "m\"ain", "main\"", "main\"", "ma\"in", "mai\"n",
		"main\'", "main\'", "ma\'in", "mai\'n", "ma\'i\'n", "ma\"i\"n",
		"ma\'inn", "ma\"inn", "ma\"\"in\'n", "ma\'\'in\"n",
		"\'\'\'\'\'\'", "\"\"\"\"\"\"",
		NULL};

	test_trim_tokens(_expected, _tokens);
}

MU_TEST_SUITE(tokens_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(stress_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(tokens_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
