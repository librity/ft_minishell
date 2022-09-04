/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 14:56:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>
# include <stdint.h>

/******************************************************************************\
 * HASH TABLE
\******************************************************************************/

typedef struct s_hash_table
{
	t_dlist			**index_lists;
	int				size;
	int				count;
}					t_hash_table;

typedef struct s_ht_item
{
	char			*key;
	char			*value;
}					t_ht_item;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_minishell
{
	bool			debug;

	int				argc;
	char			**argv;
	char			**envp;

	t_hash_table	*envht;

	t_list			*lalloc;
}					t_minishell;

/******************************************************************************\
 * CRYPTO
\******************************************************************************/

typedef struct s_md5
{
	void			*message;
	size_t			msg_length;

	uint32_t		chunks;
	uint8_t			*padded_message;

	uint32_t		*digest;
}					t_md5;

typedef enum e_chuck_digest_ints
{
	_A = 0,
	_B = 1,
	_C = 2,
	_D = 3,
	_FIRST = _A,
	_LAST = _D
}					t_chuck_digest_ints;

#endif
