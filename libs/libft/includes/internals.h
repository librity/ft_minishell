/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:58:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include <libft.h>

/******************************************************************************\
 * ERRORS
\******************************************************************************/

# define ERROR_PREFIX "ERROR:\t"

/******************************************************************************\
 * MEMORY
\******************************************************************************/

# define SALLOC_ERR "Unable to allocate required memory."

/******************************************************************************\
 * SHELL
\******************************************************************************/

# define CLEAR_ESCAPE_SEQUENCE "\e[1;1H\e[2J"

/******************************************************************************\
 * PRINT NUMBERS
\******************************************************************************/

# define DEFAULT_PRINT_FLOAT_PRECISION 6

# define UC_LOWERCASE_HEX_SIZE 2
# define UI_LOWERCASE_HEX_SIZE 8

# define DECIMAL_BASE "0123456789"
# define LOWERCASE_HEX_BASE "0123456789abcdef"
# define UPPERCASE_HEX_BASE "0123456789ABCDEF"

# define BASE_ERR "Bad number base."

/******************************************************************************\
 * NUMBER TO STRING
\******************************************************************************/

# define INT_STRING_MAX_LENGTH 11
# define UINT_STRING_MAX_LENGTH 10

/******************************************************************************\
 * PRINT STRINGS
\******************************************************************************/

# define WRITE_ERR "Unable to write byte to file descriptor."

/******************************************************************************\
 * LINKED LIST
\******************************************************************************/

# define LIST_INIT_REFERENCE_ERR "Initializing linked list \
with NULL reference."
# define LIST_INIT_NONEMPTY_ERR "Initializing non-empty linked list."

/******************************************************************************\
 * DOUBLY LINKED LIST
\******************************************************************************/

# define DLIST_INIT_REFERENCE_ERR "Initializing doubly linked list \
with NULL reference."
# define DLIST_INIT_NONEMPTY_ERR "Initializing non-empty doubly linked list."

# define DLIST_GET_SAFE_LIST_ERR "Getting node from empty or uninitialized \
doubly linked linked."
# define DLIST_GET_SAFE_INDEX_ERR "Getting node with out-of-bounds index \
from doubly linked list."

/******************************************************************************\
 * FT_GET_NEXT_LINE
\******************************************************************************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define MAX_FILE_DESCRIPTOR RLIMIT_NOFILE

# define GNL_ERROR_MESSAGE "Unable to read next line of required file"

/******************************************************************************\
 * FT_PRINTF
\******************************************************************************/

# define NULL_STRING "(null)"
# define DEBUG_SUFFIX "DEBUG:\t"

typedef struct s_printf
{
	const char		*format;
	va_list			elements;
	int				chars_printed;
	unsigned int	conversion_position;
	char			conversion;
}					t_printf;

typedef struct s_parse_flags
{
	char			parsed_flags[FT_ARG_MAX];
	char			*flags;
	bool			has_wildcards;
	bool			is_left_padded_with_zeros;
	bool			is_left_justified;
	char			left_padder;
	bool			has_minimum_width;
	int				minimum_width;
	bool			has_precision;
	int				precision;
}					t_parse_flags;

typedef struct s_parse_wildcards
{
	char			*found_wildcards;
	unsigned int	conversion_position;
	int				wildcard;
	size_t			parser;
}					t_parse_wildcards;

void				pf_vprintf(t_printf *print_control);

void				pf_initialize_print_control(t_printf *print_control,
						const char *format);
void				pf_initialize_flag_control(t_printf *print_control,
						t_parse_flags *flag_control);
void				pf_initialize_wildcard_control(t_printf *print_control,
						t_parse_flags *flag_control,
						t_parse_wildcards *wildcard_control);

void				pf_parse_flags(t_printf *print_control,
						t_parse_flags *control);
void				pf_parse_wildcars(t_printf *print_control,
						t_parse_flags *flag_control);

bool				pf_handled_no_conversion(t_printf *print_control);

/******************************************************************************\
 * FT_PRINTF PERCENT
\******************************************************************************/

typedef struct s_handle_percent
{
	unsigned char	print_me;
	int				char_count;
	t_parse_flags	flag_control;
}					t_handle_percent;
bool				pf_handled_percent(t_printf *print_control);
void				pf_print_percent(t_printf *print_control,
						t_handle_percent *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF CHAR
\******************************************************************************/

typedef struct s_handle_c
{
	unsigned char	print_me;
	int				char_count;
	t_parse_flags	flag_control;
}					t_handle_c;
bool				pf_handled_s(t_printf *print_control);
void				pf_print_c(t_printf *print_control,
						t_handle_c *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF STRING
\******************************************************************************/

typedef struct s_handle_s
{
	char			*print_me;
	size_t			length;
	size_t			precision_length;
	bool			is_null;
	t_parse_flags	flag_control;
}					t_handle_s;
bool				pf_handled_c(t_printf *print_control);
void				pf_print_s(t_printf *print_control,
						t_handle_s *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF INT
\******************************************************************************/

typedef struct s_handle_int
{
	long			print_me;
	int				digit_count;
	int				char_count;
	bool			is_negative;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_int;
bool				pf_handled_int(t_printf *print_control);
void				pf_print_int(t_printf *print_control,
						t_handle_int *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF UNSIGNED INT
\******************************************************************************/

typedef struct s_handle_u
{
	unsigned int	print_me;
	int				digit_count;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_u;
bool				pf_handled_u(t_printf *print_control);
void				pf_print_u(t_printf *print_control,
						t_handle_u *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF POINTERS
\******************************************************************************/

typedef struct s_handle_p
{
	unsigned long	print_me;
	int				digit_count;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_p;
bool				pf_handled_p(t_printf *print_control);
void				pf_printf_p(t_printf *print_control,
						t_handle_p *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF HEXADECIMAL
\******************************************************************************/

typedef struct s_handle_hex
{
	unsigned int	print_me;
	int				digit_count;
	bool			is_uppercase;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_hex;
bool				pf_handled_hex(t_printf *print_control);
void				pf_printf_hex(t_printf *print_control,
						t_handle_hex *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF FLOAT DOUBLE
\******************************************************************************/

typedef struct s_handle_f
{
	double			print_me;
	int				digit_count;
	int				char_count;
	bool			is_negative;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_f;
bool				pf_handled_f(t_printf *print_control);
void				pf_print_f(t_printf *print_control,
						t_handle_f *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF LONG DOUBLE
\******************************************************************************/

typedef struct s_handle_lf
{
	long double		print_me;
	int				digit_count;
	int				char_count;
	bool			is_negative;
	bool			is_zero_with_zero_precision;
	t_parse_flags	flag_control;
}					t_handle_lf;
bool				pf_handled_lf(t_printf *print_control);
void				pf_print_lf(t_printf *print_control,
						t_handle_lf *control,
						t_parse_flags *flag_control);

/******************************************************************************\
 * FT_PRINTF MINUS SIGN
\******************************************************************************/

void				pf_handle_minus_sign_l(long *number_pointer);
void				pf_handle_minus_sign_ll(long long *number_pointer);

void				pf_handle_minus_sign_f(float *number_pointer);
void				pf_handle_minus_sign_d(double *number_pointer);
void				pf_handle_minus_sign_ld(long double *number_pointer);

#endif
