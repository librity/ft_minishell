/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnode.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 13:42:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

t_parse	*_node;
void	*_empty;
char	**tokens;

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(new_tst)
{
	_node = new_pnode();
	mu_check(_node != NULL);

	_empty = ft_calloc(sizeof(t_parse), 1);
	mu_check(0 == ft_memcmp(_node, _empty, sizeof(t_parse)));
	mu_assert_int_eq(PT_NULL, _node->type);

	_node->file.fd = 42;
	mu_assert_int_eq(42, _node->file.fd);

	destroy_pnode(&_node);
	free(_empty);
}

MU_TEST(new_exec_tst)
{
	char **command_tokens = (char *[]){"ls", "-la", NULL};
	_node = new_exec_pnode(command_tokens);

	mu_assert_int_eq(PT_EXEC, _node->type);
	mu_assert_string_eq("ls", _node->exec.cmd);
	assert_strarr_eq(command_tokens, _node->exec.argv);

	destroy_pnode(&_node);
}

MU_TEST(new_pipe_tst)
{
	_node = new_pipe_pnode();
	mu_assert_int_eq(PT_PIPE, _node->type);

	destroy_pnode(&_node);
}

MU_TEST(new_truncate_tst)
{
	_node = new_truncate_pnode("./path/to/file");

	mu_assert_string_eq("./path/to/file", _node->file.path);
	mu_assert_int_eq(PT_TRUNCATE, _node->type);

	destroy_pnode(&_node);
}

MU_TEST(new_append_tst)
{
	_node = new_append_pnode("./path/to/file");

	mu_assert_string_eq("./path/to/file", _node->file.path);
	mu_assert_int_eq(PT_APPEND, _node->type);

	destroy_pnode(&_node);
}

MU_TEST(new_read_file_tst)
{
	_node = new_read_file_pnode("./path/to/file");

	mu_assert_string_eq("./path/to/file", _node->file.path);
	mu_assert_int_eq(PT_READ_FILE, _node->type);

	destroy_pnode(&_node);
}

MU_TEST(new_heredoc_tst)
{
	_node = new_heredoc_pnode("dELimITer");

	mu_assert_string_eq("dELimITer", _node->delimiter);
	mu_assert_int_eq(PT_HEREDOC, _node->type);

	destroy_pnode(&_node);
}

MU_TEST(destroy_tst)
{
	_node = new_pnode();

	_node->exec.argv = ft_strarr_dup((char *[]){"gar", "mon", "bo", "zia", NULL});
	_node->exec.cmd = ft_strdup("gar");
	_node->exec.path = ft_strdup("/sbin/gar");
	_node->exec.code = 42;

	_node->file.path = ft_strdup("file");
	_node->file.fd = 42;

	_node->delimiter = ft_strdup("garmonbozia");

	_node->type = 42;

	destroy_pnode(&_node);
	mu_check(_node == NULL);
}

MU_TEST_SUITE(pnode_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(new_tst);

	MU_RUN_TEST(new_exec_tst);
	MU_RUN_TEST(new_pipe_tst);
	MU_RUN_TEST(new_truncate_tst);
	MU_RUN_TEST(new_append_tst);
	MU_RUN_TEST(new_read_file_tst);
	MU_RUN_TEST(new_heredoc_tst);

	MU_RUN_TEST(destroy_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pnode_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
