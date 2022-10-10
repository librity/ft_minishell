/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randlloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:40:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/08 19:04:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc randlloc.c && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	randlloc(int modulo)
{
	size_t	random;

	// random = malloc(1);
	random = (size_t)calloc(1, 1);
	// free(random);
	return ((unsigned int)random % modulo);
}

int	main(void)
{
	int	i;

	i = 10;
	while (i--)
		printf("%d, ", randlloc(100));
	printf("\n");
	return (EXIT_SUCCESS);
}
