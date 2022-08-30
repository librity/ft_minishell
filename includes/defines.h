/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 15:30:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * LEXER
\******************************************************************************/

# define NOT_ASCII -42
# define DELIMITER -42
# define SPACE ' '

# define SINGLE_QUOTE '\''
# define DOUBLE_QUOTE '\"'

# define VERTICAL_BAR '|'

# define GREATER_THAN '>'
# define TRUNCATE ">"
# define APPEND ">>"

# define LESS_THAN '<'
# define READ_FILE "<"
# define HEREDOC "<<"

/******************************************************************************\
 * CRYPTO
\******************************************************************************/

# define ONE_BIT 0b10000000
# define NULL_BYTE 0b00000000

# define MD5_DIGEST_SIZE 16
# define MD5_HASH_SIZE 33

/******************************************************************************\
 * HASH TABLE
\******************************************************************************/

# define HASH_TABLE_SIZE 10000

/******************************************************************************\
 * ERRORS
\******************************************************************************/

# define ERR_GENERIC "Error\n"

#endif
