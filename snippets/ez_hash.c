/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:40:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/24 23:15:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// There is no such thing as extended ASCII...
// gcc ez_hash.c && ./a.out

#include <stdio.h>

#define TBLSIZE 99

static unsigned int	ez_hash(const char *key)
{
	int				counter;
	unsigned int	val;
	unsigned int	tmp;

	counter = 0;
	val = 0;
	while (key[counter])
	{
		val += key[counter];
		tmp = val & 0xf0000000;
		if (tmp)
		{
			val = val ^ (tmp >> 24);
			val = val ^ tmp;
		}
		counter += 1;
	}
	return (val % TBLSIZE);
}

static void	print_ez_hash(char *str)
{
	printf("'%s': %d\n", str, ez_hash(str));
}

int	main(void)
{
	char	*str;

	str = "I'm a little teapot short and stout.";
	print_ez_hash(str);

	str = "Here is my handle, here is my spout!";
	print_ez_hash(str);
	return (0);
}
