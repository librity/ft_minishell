/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 15:35:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static void	test_trim_token(char *expected, char *token)
{
	char	*trim_me;

	trim_me = ft_strdup(token);
	trim_token(trim_me);
	mu_assert_string_eq(expected, trim_me);
	free(trim_me);
}

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(single_quote_tst)
{
	test_trim_token("main", "\'main\'");
	test_trim_token("main", "ma\'in\'");
	test_trim_token("main", "\'ma\'in");
	test_trim_token("main", "m\'ai\'n");

	test_trim_token("main", "\'main");
	test_trim_token("main", "ma\'in");
	test_trim_token("main", "main\'");

	test_trim_token("main", "\'m\'ai\'n");
	test_trim_token("main", "m\'ai\'n\'");

	test_trim_token("main", "m\'a\'i\'n\'");
}

MU_TEST(double_quote_tst)
{
	test_trim_token("main", "\"main\"");
	test_trim_token("main", "ma\"in\"");
	test_trim_token("main", "\"ma\"in");
	test_trim_token("main", "m\"ai\"n");

	test_trim_token("main", "\"main");
	test_trim_token("main", "ma\"in");
	test_trim_token("main", "main\"");

	test_trim_token("main", "\"m\"ai\"n");
	test_trim_token("main", "m\"ai\"n\"");

	test_trim_token("main", "m\"a\"i\"n\"");
}

MU_TEST(mixed_quote_tst)
{
	test_trim_token("m\'ain", "\"m\'ai\"n");
	test_trim_token("m\"ain", "\'m\"ai\'n");

	test_trim_token("main\"", "\'main\"");
	test_trim_token("main\"", "ma\'in\"");
	test_trim_token("ma\"in", "\'ma\"in");
	test_trim_token("mai\"n", "m\'ai\"n");

	test_trim_token("main\'", "\"main\'");
	test_trim_token("main\'", "ma\"in\'");
	test_trim_token("ma\'in", "\"ma\'in");
	test_trim_token("mai\'n", "m\"ai\'n");

	test_trim_token("ma\'i\'n", "m\"a\'i\'n\"");
	test_trim_token("ma\"i\"n", "m\'a\"i\"n\'");

	test_trim_token("ma\'inn", "m\'a\'\"\'i\"n\'n");
	test_trim_token("ma\"inn", "m\"a\"\'\"i\'n\"n");

	test_trim_token("ma\"\"in\'n", "m\'a\"\"\'i\"n\'n");
	test_trim_token("ma\'\'in\"n", "m\"a\'\'\"i\'n\"n");

	test_trim_token("\'\'\'\'\'\'", "\"\'\'\'\'\'\'\"");
	test_trim_token("\"\"\"\"\"\"", "\'\"\"\"\"\"\"\'");
}

MU_TEST(empty_tst)
{
	test_trim_token("helloworld", "hello\"\"world");
	test_trim_token("helloworld", "hello\'\'world");

	test_trim_token("helloworld", "hello\"\"\"\"world");
	test_trim_token("helloworld", "hello\'\'\'\'world");

	test_trim_token("helloworld", "hello\"\"\'\'world");
	test_trim_token("helloworld", "hello\'\'\"\"world");
}

MU_TEST_SUITE(token_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(single_quote_tst);
	MU_RUN_TEST(double_quote_tst);

	MU_RUN_TEST(mixed_quote_tst);

	MU_RUN_TEST(empty_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(token_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
