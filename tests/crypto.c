/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/29 00:08:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char *digest;
char *expected;

static void test_md5(char *expected, char *message)
{
	digest = md5_hex(message);

	mu_assert_string_eq(expected, digest);
	free(digest);
}

static void example_setup(void)
{
}
static void example_teardown(void)
{
}

MU_TEST(md5_test)
{
	test_md5(
		"9e107d9d372bb6826bd81d3542a419d6",
		"The quick brown fox jumps over the lazy dog");

	test_md5(
		"e4d909c290d0fb1ca068ffaddf22cbd0",
		"The quick brown fox jumps over the lazy dog.");

	test_md5(
		"d41d8cd98f00b204e9800998ecf8427e",
		"");

	test_md5(
		"ee123eff2ad7fffcc6e8866acc300ea9",
		"ca sad asdas da asd a");

	test_md5(
		"a088672c20cee82993621b050c0d0460",
		"r ewreworwjprjpwejr wer wo rwfcf def ef sdgsfdgdfg sfgsfssdfg\
fs gerfffffffffffffffffffffdfffffffffffffffffffffffffffffffffffffffffffffffffff\
fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff\
fffffffffffffffffffffffff");
}

MU_TEST_SUITE(example_suite)
{
	MU_SUITE_CONFIGURE(&example_setup, &example_teardown);
	MU_RUN_TEST(md5_test);
}

int main(void)
{
	MU_RUN_SUITE(example_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
