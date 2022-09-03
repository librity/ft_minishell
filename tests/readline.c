/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/02 16:39:45 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*line;
bool	_bool;

static void	example_setup(void)
{
}
static void	example_teardown(void)
{
}

MU_TEST(get_input_tst)
{
	write(STDIN_FILENO, "teste",5);
	read_stdin();
}

MU_TEST(check_asp_tst)
{
	_bool = verf_clone_quote("\"teste\'\"");
	mu_check(_bool == true);

	_bool = verf_clone_quote("\'teste2\"\'");
	mu_check(_bool == true);

	_bool = verf_clone_quote("\'teste3\'\"");
	mu_check(_bool == false);

	_bool = verf_clone_quote("\'teste4\"\"");
	mu_check(_bool == false);

	_bool = verf_clone_quote("\"\'teste5\'");
	mu_check(_bool == false);
}

MU_TEST_SUITE(example_suite)
{
	MU_SUITE_CONFIGURE(&example_setup, &example_teardown);
	//MU_RUN_TEST(check_asp_tst);
	MU_RUN_TEST(get_input_tst);
}

int	main(void)
{
	MU_RUN_SUITE(example_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
