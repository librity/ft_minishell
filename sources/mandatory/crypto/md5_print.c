/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 16:41:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_md5(uint32_t *digest)
{
	ft_printf("\"%08x%08x%08x%08x\"", digest[0], digest[1], digest[2], digest[3]);
}

void	inspect_md5(char *message, uint32_t *digest)
{
	ft_printf("md5(\"%s\") => ", message);
	print_md5(digest);
	ft_printf("\n");
}
