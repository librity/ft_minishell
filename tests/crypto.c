/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/28 00:40:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char *digest;
char *expected;

static void example_setup(void)
{
}
static void example_teardown(void)
{
}

MU_TEST(md5_test)
{
	// digest = md5("The quick brown fox jumps over the lazy dog");
	// expected = "9e107d9d372bb6826bd81d3542a419d6";
	// mu_assert_string_eq(expected, digest);

	// digest = md5("The quick brown fox jumps over the lazy dog.");
	// expected = "e4d909c290d0fb1ca068ffaddf22cbd0";
	// mu_assert_string_eq(expected, digest);

	digest = md5("");
	expected = "d41d8cd98f00b204e9800998ecf8427e";
	mu_assert_string_eq(expected, digest);

	// digest = md5("ca sad asdas da asd a");
	// expected = "ee123eff2ad7fffcc6e8866acc300ea9";
	// mu_assert_string_eq(expected, digest);

// 	digest = md5("r ewreworwjprjpwejr wer wo rwfcf def ef sdgsfdgdfg sfgsfssdfg\
// fs gerfffffffffffffffffffffdfffffffffffffffffffffffffffffffffffffffffffffffffff\
// fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff\
// fffffffffffffffffffffffff");
// 	expected = "a088672c20cee82993621b050c0d0460";
// 	mu_assert_string_eq(expected, digest);
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
