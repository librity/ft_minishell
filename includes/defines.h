/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 18:07:59 by lpaulo-m         ###   ########.fr       */
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
# define APPEND ">"
# define TRUNCATE ">>"

# define LESS_THAN '<'
# define READ_FILE "<"
# define HEREDOC "<<"

/******************************************************************************\
 * ERRORS
\******************************************************************************/

# define ERR_GENERIC "Error\n"

#endif
