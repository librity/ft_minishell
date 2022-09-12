/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:53:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 22:42:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../tests.h"

void compare_pnode(void *expected, void *result)
{
	t_parse *_expected;
	t_parse *_result;

	_expected = (t_parse *)expected;
	_result = (t_parse *)result;

	mu_assert_int_eq(_expected->type, _result->type);

	assert_strarr_eq(_expected->tokens, _result->tokens);
	mu_assert_string_eq(_expected->file_path, _result->file_path);
	mu_assert_string_eq(_expected->delimiter, _result->delimiter);
}

#endif
