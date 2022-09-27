/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:34:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/27 15:49:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc dictionary.c && ./a.out

#include <stdbool.h>
#include <stdio.h>

typedef struct s_dict
{
	char *key;
	void *value;
} t_dict;

bool ft_streq(char *s1, char *s2)
{
	if (s1 == s2)
		return (true);
	if (s1 == NULL || s2 == NULL)
		return (false);
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return (false);
	return (true);
}

void *ft_dict_find(const t_dict **dictionary, char *key)
{
	t_dict **node;

	node = (t_dict **)dictionary;
	while (*node != NULL)
	{
		if (ft_streq(key, (*node)->key))
			return ((*node)->value);
		node++;
	}
	return (NULL);
}

typedef void (*t_vfuncv)(void);

void hello(void)
{
	printf("Hello!\n");
}

void *find_my_dict(char *name)
{
	static int number = 42;
	const t_dict *_builtins[] = {
		&(const t_dict){"function", hello},
		&(const t_dict){"string", "foobar"},
		&(const t_dict){"number", &number},
		NULL};

	return (ft_dict_find(_builtins, name));
}

bool is_in_mid_dict(char *name)
{
	if (find_my_dict(name) == NULL)
		return (false);
	return (true);
}

int main(void)
{
	int number;
	t_vfuncv callback;
	char *str;

	printf("%s is in my_dict %d\n", "string", is_in_mid_dict("string"));
	str = find_my_dict("string");
	printf("%s: %s\n", "string", str);
	printf("===\n");

	printf("%s is in my_dict %d\n", "function", is_in_mid_dict("function"));
	callback = find_my_dict("function");
	callback();
	printf("===\n");

	printf("%s is in my_dict %d\n", "number", is_in_mid_dict("number"));
	number = *(int *)find_my_dict("number");
	printf("%s: %d\n", "number", number);
	printf("===\n");

	printf("%s is in my_dict %d\n", "badbad", is_in_mid_dict("badbad"));
	printf("%s: %p\n", "badbad", find_my_dict("badbad"));
	printf("===\n");

	return (0);
}
