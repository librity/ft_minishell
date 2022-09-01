/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/31 19:01:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char *hex_digest;
char *expected;
uint32_t	sum;

static void test_md5_hex(char *expected, char *message)
{
	hex_digest = md5_hex(message);

	mu_assert_string_eq(expected, hex_digest);
	free(hex_digest);
}

static void example_setup(void)
{
}
static void example_teardown(void)
{
}

MU_TEST(md5_hex_tst)
{
	test_md5_hex(
		"9e107d9d372bb6826bd81d3542a419d6",
		"The quick brown fox jumps over the lazy dog");

	test_md5_hex(
		"e4d909c290d0fb1ca068ffaddf22cbd0",
		"The quick brown fox jumps over the lazy dog.");

	test_md5_hex(
		"d41d8cd98f00b204e9800998ecf8427e",
		"");

	test_md5_hex(
		"6e8fe3fa3d1ef606acbdc948ea590df5",
		"I really want to go to work, but I am too sick to drive.");

	test_md5_hex(
		"f84789d6c6603b4bb6ea7bc860d15cad",
		"I hear that Nancy is very pretty.");

	test_md5_hex(
		"41ebec28f8dab794365bad9e178ace1a",
		"She was sad to hear that fireflies are facing extinction due to artificial light, habitat loss, and pesticides.");

	test_md5_hex(
		"32b3ef796c28447af80a9492ab087f64",
		"I made myself a peanut butter sandwich as I didn't want to subsist on veggie crackers.");

	test_md5_hex(
		"cc2fa1a51d9bf47748ca37a52fc7ed88",
		"Three years later, the coffin was still full of Jello.");

	test_md5_hex(
		"454cc13bdee37176a2dd0bd050951d85",
		"Henry couldn't decide if he was an auto mechanic or a priest.");

	test_md5_hex(
		"b3121cbfa23a09d0031f7262cb63c5b6",
		"He found the chocolate covered roaches quite tasty.");

	test_md5_hex(
		"c002022c1251bb171767cf1520e569c5",
		"His ultimate dream fantasy consisted of being content and sleeping eight hours in a row.");

	test_md5_hex(
		"d9f45b8d75b8dda1f4d8976e6eea0483",
		"Homesickness became contagious in the young campers' cabin.");

	test_md5_hex(
		"4d116053d4a115b197ef9a86a07fa17a",
		"I felt then dead like the men who slept 'neath fields of Garryowen.");

	test_md5_hex(
		"27643c200c897a5d88502a4895b807dc",
		"She looked into the mirror and saw another person.");

	test_md5_hex(
		"08b765f9c63d5f9149e9e4506dee7f7e",
		"It's a skateboarding penguin with a sunhat!");

	test_md5_hex(
		"9db823121b78dd8bdbef43ba5c1f8414",
		"Bill ran from the giraffe toward the dolphin.");

	test_md5_hex(
		"82a5218cae8be045f56d45ef931b520c",
		"Kevin embraced his ability to be at the wrong place at the wrong time.");

	test_md5_hex(
		"d3c2db0f36d06b3b0b05cc36b82f399e",
		"She hadn't had her cup of coffee, and that made things all the worse.");

	test_md5_hex(
		"d7ca9f90df7551f1f32c84b741def313",
		"I'm worried by the fact that my daughter looks to the local carpet seller as a role model.");

	test_md5_hex(
		"79516e4d0112b3ac4c68b5da1f174c0d",
		"He invested some skill points in Charisma and Strength.");

	test_md5_hex(
		"647f49fefd74fdfc2fbfe79d76962a0c",
		"I cheated while playing the darts tournament by using a longbow.");

	test_md5_hex(
		"b253b2723573e25edbd2701600117005",
		"He barked orders at his daughters but they just stared back with amusement.");

	test_md5_hex(
		"1fe435bb2235eaeed0cacc93b02998d3",
		"Fhir a' bhata, 'S tric mi sealltainn on chnoc as airde (Gach ait' an teid thu...) Dh'fheuch am faic mi fear a' bhata. (Gach ait' an teid thu...)");

	test_md5_hex(
		"13c5de82cf6b393d2f650a1e28e7374c",
		"I was fishing for compliments and accidentally caught a trout.");

	test_md5_hex(
		"d3ae33d3f1bf9de074e1567470b7e789",
		"The external scars tell only part of the story.");

	test_md5_hex(
		"b5af5a347ef00ab5d24796d5d6ec853f",
		"Sometimes the light's all shinin' on me Other times I can barely see Lately it occurs to me What a long, strange trip it's been");

	test_md5_hex(
		"ee123eff2ad7fffcc6e8866acc300ea9",
		"ca sad asdas da asd a");

	test_md5_hex(
		"625d65ac781b40f2f9ec6bc283b6408e",
		"https://md5calc.com/hash");

	test_md5_hex(
		"88525c36145ce7a99cc3956a74b73fe7",
		"b5af5a347ef00ab5d24796d5d6ec853f2367e09ee21ae1e4b8d412b34f0c0df35b7919\
c3fca98084dbf2bfdccf0cefb368252fe6a8b823215cc6bae394cfbcef03e99d0d7664dc43b53cd\
0adc94130d7055735c09a4b2e1751a9478667f61699c4919605acf4255e1f3ac3d4ad9608abfe4f\
2414b6ac4379039efa341077965e8bfe574cc30ce1a24263e268f311df83");

	test_md5_hex(
		"a088672c20cee82993621b050c0d0460",
		"r ewreworwjprjpwejr wer wo rwfcf def ef sdgsfdgdfg sfgsfssdfg\
fs gerfffffffffffffffffffffdfffffffffffffffffffffffffffffffffffffffffffffffffff\
fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff\
fffffffffffffffffffffffff");
}

MU_TEST(md5_sum_tst)
{
	sum = md5_sum("If I had more time I would write fewer words.");
	mu_assert_int_eq(52072297, sum);
}

MU_TEST_SUITE(example_suite)
{
	MU_SUITE_CONFIGURE(&example_setup, &example_teardown);
	MU_RUN_TEST(md5_hex_tst);
	MU_RUN_TEST(md5_sum_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(example_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
