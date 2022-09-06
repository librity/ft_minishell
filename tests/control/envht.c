/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envht.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/06 15:31:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

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

	deinitialize_control();
}

MU_TEST(initialize_tst)
{
	c()->envp = (char *[]){"gar=mon", NULL};
	mu_check(NULL == envht());
	initialize_envht();
	mu_check(NULL != envht());

	_envht = c()->envht;
	stdout_to_devnull();
	initialize_envht();
	restore_stdout();
	mu_check(_envht == envht());

	ht_destroy(&(c()->envht));
	deinitialize_control();
}

MU_TEST(initialize_with_envp_tst)
{
	c()->envp = (char *[]){
		"foo=bar",
		"fizz=buzz",
		"gar=mon",
		"bo=zia",
		NULL};
	mu_check(true == initialize_envht());

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

void envht_init_die_1(void)
{
	c()->envp = (char *[]){
			"foo=bar",
			"garmon",
			"bo=zia",
			NULL};
	stdout_to_devnull();
	initialize_envht();
}
void envht_init_die_2(void)
{
	c()->envp = (char *[]){
			"foobar",
			"gar=mon",
			"bo=zia",
			NULL};
	stdout_to_devnull();
	initialize_envht();
}
MU_TEST(initialize_die_tst)
{
	test_die(envht_init_die_1);
	test_die(envht_init_die_2);
}

MU_TEST(initialize_empty_variable_tst)
{
	c()->envp = (char *[]){
			"foo=bar",
			"gar=",
			"bo=zia",
			NULL};
	mu_check(true == initialize_envht());

	_str = ht_get(envht(), "foo");
	mu_assert_string_eq("bar", _str);

	_str = ht_get(envht(), "gar");
	mu_assert_string_eq("", _str);

	_str = ht_get(envht(), "bo");
	mu_assert_string_eq("zia", _str);

	ht_destroy(&(c()->envht));
}

MU_TEST(destroy_tst)
{
	stdout_to_devnull();
	destroy_envht();
	restore_stdout();

	c()->envp = (char *[]){"gar=mon", NULL};
	initialize_envht();
	destroy_envht();
	mu_check(c()->envht == NULL);

	stdout_to_devnull();
	destroy_envht();
	restore_stdout();
}

MU_TEST(envht_to_envp_tst)
{
	c()->envp = (char *[]){
		"foo=bar",
		"fizz=buzz",
		"gar=mon",
		"bo=zia",
		NULL};
	initialize_envht();

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

MU_TEST_SUITE(envht_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(envht_tst);

	MU_RUN_TEST(initialize_tst);
	MU_RUN_TEST(initialize_with_envp_tst);
	MU_RUN_TEST(initialize_die_tst);
	MU_RUN_TEST(initialize_empty_variable_tst);

	MU_RUN_TEST(destroy_tst);

	MU_RUN_TEST(envht_to_envp_tst);
	MU_RUN_TEST(envht_to_envp_null_tst);
}

int main(int argc, char **argv, char **envp)
{
	MU_DIVIDER;
	MU_RUN_SUITE(envht_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
