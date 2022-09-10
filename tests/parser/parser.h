/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:53:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/10 12:39:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../tests.h"

void compare_pnode(void *expected, void *result)
{
	t_pnode *_expected;
	t_pnode *_result;

	_expected = (t_pnode *)expected;
	_result = (t_pnode *)result;

	assert_strarr_eq(_expected->exec.tokens, _result->exec.tokens);
	mu_assert_string_eq(_expected->exec.cmd, _result->exec.cmd);
	mu_assert_string_eq(_expected->exec.path, _result->exec.path);
	mu_assert_int_eq(_expected->exec.code, _result->exec.code);

	mu_assert_string_eq(_expected->file.path, _result->file.path);
	mu_assert_int_eq(_expected->file.fd, _result->file.fd);

	mu_assert_string_eq(_expected->delimiter, _result->delimiter);

	mu_assert_int_eq(_expected->type, _result->type);
}

#endif
