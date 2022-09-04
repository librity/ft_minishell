/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:53:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 18:49:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include "tests.h"

int				g_index;
t_hash_table	*g_table;

void	test_ht_item(t_ht_item *_item,
					char *expected_key,
					char *expected_value)
{
	mu_check(_item != NULL);
	mu_assert_string_eq(expected_key, _item->key);
	mu_assert_string_eq(expected_value, _item->value);
}

void	seed_ht(void)
{
	ht_insert(g_table, "foo", "bar");
	ht_insert(g_table, "baz", "fizz");
	ht_insert(g_table, "buzz", "crash");
}

void	seed_ht_fixed_index(void)
{
	g_index = 42;
	ht_insert_in_index(g_table, "foo", "bar", g_index);
	ht_insert_in_index(g_table, "baz", "fizz", g_index);
	ht_insert_in_index(g_table, "buzz", "crash", g_index);
}

#endif
