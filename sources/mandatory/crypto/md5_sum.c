/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:15:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 15:31:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

uint32_t	md5_sum(char *message)
{
	uint32_t	*digest;
	uint32_t	sum;

	digest = md5_big_endian(message, ft_strlen(message));
	sum = digest[0] + digest[1] + digest[2] + digest[3];
	free(digest);
	return (sum);
}
