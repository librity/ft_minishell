/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/01 17:58:50 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*line;

static void	example_setup(void)
{
}
static void	example_teardown(void)
{
}

MU_TEST(get_line_test)
{
	mu_assert_string_eq(line, "teste\n");
}

MU_TEST_SUITE(example_suite)
{
	MU_SUITE_CONFIGURE(&example_setup, &example_teardown);
	MU_RUN_TEST(get_line_test);
}

int	main(void)
{
	MU_RUN_SUITE(example_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
