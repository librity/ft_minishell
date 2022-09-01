/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 22:57:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>
# include <stdint.h>

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_minishell
{
	bool		debug;

	int			argc;
	char		**argv;
	char		**envp;

	t_list		*lalloc;
}				t_minishell;

/******************************************************************************\
 * CRYPTO
\******************************************************************************/

typedef struct s_md5
{
	void		*message;
	size_t		msg_length;

	uint32_t	chunks;
	uint8_t		*padded_message;

	uint32_t	*digest;
}				t_md5;

typedef union u_byte_word_ui32
{
	uint32_t	word;
	uint8_t		bytes[4];
}				t_byte_word_ui32;

/******************************************************************************\
 * HASH TABLE
\******************************************************************************/

typedef struct s_hash_table
{
	t_dlist		**index_lists;
	int			size;
	int			count;
}				t_hash_table;

typedef struct s_ht_item
{
	char		*key;
	char		*value;
}				t_ht_item;

#endif
