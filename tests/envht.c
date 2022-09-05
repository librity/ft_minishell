/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envht.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/05 01:54:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_hash_table	*_envht;
char			*_str;
char			**_strarr;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(envht_tst)
{
	c()->envht = (void *)42;
	mu_check((void *)42 == envht());

	ft_bzero(c(), sizeof(t_minishell));
}

MU_TEST(initilize_envht_tst)
{
	mu_check(NULL == envht());
	initilize_envht();
	mu_check(NULL != envht());

	_envht = c()->envht;
	initilize_envht();
	mu_check(_envht == envht());

	ht_destroy(&(c()->envht));
}

MU_TEST(initilize_envht_with_envp_tst)
{
	c()->envp = (char *[]){
		"foo=bar",
		"fizz=buzz",
		"gar=mon",
		"bo=zia",
		NULL};
	initilize_envht();

	_str = ht_get(envht(), "foo");
	mu_assert_string_eq("bar", _str);

	_str = ht_get(envht(), "fizz");
	mu_assert_string_eq("buzz", _str);

	_str = ht_get(envht(), "gar");
	mu_assert_string_eq("mon", _str);

	_str = ht_get(envht(), "bo");
	mu_assert_string_eq("zia", _str);

	ht_destroy(&(c()->envht));
}

MU_TEST(destroy_envht_tst)
{
	destroy_envht();

	initilize_envht();
	destroy_envht();
	mu_check(c()->envht == NULL);

	destroy_envht();
}

MU_TEST(envht_to_envp_tst)
{
	c()->envp = (char *[]){
		"foo=bar",
		"fizz=buzz",
		"gar=mon",
		"bo=zia",
		NULL};
	initilize_envht();

	_strarr = envht_to_envp();
	mu_check(4 == ft_strarr_len(_strarr));

	assert_in_strarr(_strarr, "foo=bar");
	assert_in_strarr(_strarr, "fizz=buzz");
	assert_in_strarr(_strarr, "gar=mon");
	assert_in_strarr(_strarr, "bo=zia");

	ft_free_strarr(_strarr);
	ht_destroy(&(c()->envht));
}

MU_TEST(envht_to_envp_null_tst)
{
	c()->envht = NULL;
	_strarr = envht_to_envp();
	mu_check(NULL == _strarr);
}

MU_TEST_SUITE(control_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(envht_tst);

	MU_RUN_TEST(initilize_envht_tst);
	MU_RUN_TEST(initilize_envht_with_envp_tst);

	MU_RUN_TEST(destroy_envht_tst);

	MU_RUN_TEST(envht_to_envp_tst);
	MU_RUN_TEST(envht_to_envp_null_tst);
}

int main(int argc, char **argv, char **envp)
{
	MU_DIVIDER;
	MU_RUN_SUITE(control_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
