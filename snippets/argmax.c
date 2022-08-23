/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:07:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 17:13:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc argmax.c && ./a.out

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("%ld\n", sysconf(_SC_ARG_MAX));
	return (0);
}
