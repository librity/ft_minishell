/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 16:02:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	init(t_md5 *m, void *message, size_t msg_length)
{
	m->message = message;
	m->msg_length = msg_length;
}

static void	init_digest(t_md5 *m)
{
	m->digest = ft_salloc(MD5_DIGEST_SIZE);
	ft_memcpy(m->digest, md5_initial_digest(), MD5_DIGEST_SIZE);
}

static void	cleanup(t_md5 *m)
{
	free(m->padded_message);
}

uint32_t	*md5(void *message, size_t msg_length)
{
	t_md5	m;

	init(&m, message, msg_length);
	md5_pad_message(&m);
	init_digest(&m);
	md5_calculate_digest(&m);
	cleanup(&m);
	return (m.digest);
}
