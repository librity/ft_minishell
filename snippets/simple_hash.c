/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:40:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/24 23:16:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// There is no such thing as extended ASCII...
// gcc simple_hash.c && ./a.out

#include <stdio.h>

#define CAPACITY 50000 // Size of the Hash Table

unsigned long	simple_hash(char *str)
{
	unsigned long	i;

	i = 0;
	for (int j = 0; str[j]; j++)
		i += str[j];
	return (i % CAPACITY);
}

static void	print_simple_hash(char *str)
{
	printf("'%s': %ld\n", str, simple_hash(str));
}

int	main(void)
{
	char	*str;

	str = "I'm a little teapot short and stout.";
	print_simple_hash(str);
	str = "Here is my handle, here is my spout!";
	print_simple_hash(str);
	return (0);
}
