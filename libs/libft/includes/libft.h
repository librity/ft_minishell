/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:58:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 16:28:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/resource.h>
# include <unistd.h>

/******************************************************************************\
 * DEFINES
\******************************************************************************/

# ifndef FT_ARG_MAX
#  define FT_ARG_MAX 2097152
# endif

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void				ft_die(void *error_message);

/******************************************************************************\
 * BOOLEANS
\******************************************************************************/

bool				unless(bool condition);

/******************************************************************************\
 * BITS
\******************************************************************************/

void				ft_print_bits(int i);
void				ft_print_bits_i(int i);
void				ft_print_bits_ui(unsigned int ui);
void				ft_print_bits_ul(unsigned long ul);
void				ft_print_bits_ull(unsigned long long ull);

void				ft_print_bits_uc(unsigned char c);
void				ft_print_bits_c(char c);

void				ft_inspect_cstr(char *str);
void				ft_hexdump(char *tag, void *address_vp, size_t size);

int					ft_rotate_left_i(int word, int rotations);
int					ft_rotate_right_i(int word, int rotations);

uint32_t			ft_rotate_left_ui32(uint32_t word, uint32_t rotations);
uint32_t			ft_rotate_right_ui32(uint32_t word, uint32_t rotations);

uint32_t			ft_switch_byte_endianess_ui32(uint32_t old);
uint32_t			ft_switch_bit_endianess_ui32(uint32_t old);

/******************************************************************************\
 * MATH
\******************************************************************************/

int					ft_abs_i(int number);
int					ft_abs(int number);

float				ft_abs_f(float number);
double				ft_abs_d(double number);
long double			ft_abs_ld(long double number);

int					ft_min_i(int x, int y);
int					ft_max_i(int x, int y);

double				ft_min_d(double x, double y);
double				ft_max_d(double x, double y);

double				ft_clamp_d(double x, double min, double max);
int					ft_clamp_i(int x, int min, int max);

void				ft_swap(int *a, int *b);
void				ft_swap_i(int *a, int *b);

void				ft_div_mod(int dividend, int divisor,
						int *result, int *remainder);
void				ft_div_mod_i(int dividend, int divisor,
						int *result, int *remainder);

int					ft_sqrt(int number);
int					ft_sqrt_i(int number);

int					ft_pow(int base, int exponent);
int					ft_pow_i(int base, int exponent);
long long			ft_pow_ll(long long base, int exponent);

int					ft_fibonacci(int index);
int					ft_factorial(int number);

typedef struct s_map_i
{
	int				x;
	int				from_1;
	int				to_1;
	int				from_2;
	int				to_2;
}					t_map_i;

int					ft_map_clamped_i(t_map_i args);
int					ft_map_i(t_map_i args);

typedef struct s_map_d
{
	double			x;
	double			from_1;
	double			to_1;
	double			from_2;
	double			to_2;
}					t_map_d;

double				ft_map_d(t_map_d args);
double				ft_map_clamped_d(t_map_d args);

double				ft_lerp_d(double from, double to, double x);
double				ft_lerp_precise_d(double from, double to, double x);
double				ft_lerp_wsteps_d(double from, double to, double steps,
						double x);

int					ft_lerp_i(int from, int to, int x);
int					ft_lerp_precise_i(int from, int to, int x);
int					ft_lerp_wsteps_i(int from, int to, int steps, int x);

/******************************************************************************\
 * RANDOM
\******************************************************************************/

unsigned int		ft_prand(void);
unsigned int		ft_prand_range(unsigned int start, unsigned int end);

/******************************************************************************\
 * MEMORY
\******************************************************************************/

void				ft_del(void **delete_me);

void				*ft_salloc(size_t size);

void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_scalloc(size_t nmemb, size_t size);

void				*ft_realloc(void *pointer, size_t old_size,
						size_t new_size);
void				*ft_srealloc(void *pointer, size_t old_size,
						size_t new_size);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/******************************************************************************\
 * ARRAYS
\******************************************************************************/

# define ARRAY_BAD_INDEX_CODE -1

size_t				ft_arr_len(void **array);
size_t				ft_arr_size(void **array);
void				ft_free_arr(void **free_me);

/******************************************************************************\
 * CHARS
\******************************************************************************/

bool				ft_isascii(char character);
bool				ft_isdigit(char character);
bool				ft_isupper(char character);
bool				ft_islower(char character);
bool				ft_isalpha(char character);
bool				ft_isalnum(char character);
bool				ft_isprint(char character);

bool				ft_is_whitespace(char character);
bool				ft_is_plus_or_minus(char character);
bool				ft_is_decimal_char(char character);

char				ft_toupper(char character);
char				ft_tolower(char character);

/******************************************************************************\
 * STRINGS
\******************************************************************************/

char				*ft_strnew(void);

size_t				ft_strlen(const char *s);
size_t				ft_strsize(const char *s);

char				*ft_strcpy(char *dest, char *src);
void				ft_strdel(char **delete_me);
char				*ft_strnchr(const char *s, int c, unsigned int limit);

char				*ft_strdup(const char *s);
char				*ft_strdup_null(const char *str);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

bool				ft_has_char(char *str, char c);
bool				ft_has_chars(char *haystack, char *needle);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *free_me, char const *dont_free_me);
char				*ft_strjoin_free_free(char *free_me, char *free_me_too);
char				*ft_strjoin_del(char **delete_me,
						const char *dont_delete_me);
char				*ft_strjoin_del_del(char **delete_me, char **delete_me_too);

char				*ft_join_size_size(char *s1, size_t s1_size, char *s2,
						size_t s2_size);

bool				ft_starts_with(char *string, char *prefix);
bool				ft_streq(char *s1, char *s2);
bool				ft_is_empty_str(char *str);

/******************************************************************************\
 * STRING TO NUMBER
\******************************************************************************/

int					ft_atoi(const char *number_pointer);
unsigned int		ft_atoui(const char *number_pointer);
unsigned int		ft_atoui_strict(const char *number_pointer);

long				ft_atol(const char *number_pointer);
unsigned long		ft_atoul(const char *number_pointer);

long long			ft_atoll(const char *number_pointer);
unsigned long long	ft_atoull(const char *number_pointer);

double				ft_atof(const char *number_pointer);
long double			ft_atold(const char *number_pointer);

/******************************************************************************\
 * NUMBER TO STRING
\******************************************************************************/

unsigned int		ft_uc_to_buffer_base(unsigned char number, char *base,
						char *buffer);
unsigned int		ft_uc_to_buffer_lchex(unsigned char number, char *buffer);

char				*ft_itoa(int n);
unsigned int		ft_i_to_buffer(int n, char *buffer);

char				*ft_uitoa(unsigned int number);
unsigned int		ft_ui_to_buffer(unsigned int number, char *buffer);
unsigned int		ft_ui_to_buffer_base(unsigned int number, char *base,
						char *buffer);
unsigned int		ft_ui_to_buffer_lchex(unsigned int number,
						char *buffer);

char				*ft_ltoa(long n);

char				*ft_precise_ftoa(float n, int precision);
char				*ft_ftoa(float n);

char				*ft_precise_dtoa(double n, int precision);
char				*ft_dtoa(double n);

char				*ft_precise_ldtoa(long double n, int precision);
char				*ft_ldtoa(long double n);

bool				ft_str_is_int(char *str);
bool				ft_str_is_uint(char *str);

/******************************************************************************\
 * PRINT STRINGS
\******************************************************************************/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fd);

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putstr_up_to(char *str, size_t up_to);
void				ft_putendl(char *str);
void				ft_puts(char *str);

void				ft_endl(void);

/******************************************************************************\
 * PRINT NUMBERS
\******************************************************************************/

bool				ft_is_valid_base(const char *base,
						const size_t base_length);

void				ft_putnbr_fd(int number, int fd);

void				ft_putnbr(int number);
void				ft_putnbr_i(int number);
void				ft_putnbr_ui(unsigned int number);
void				ft_putnbr_l(long number);
void				ft_putnbr_ul(unsigned long number);
void				ft_putnbr_ll(long long number);
void				ft_putnbr_ull(unsigned long long number);

void				ft_putnbr_base(int number, char *base);
void				ft_putnbr_base_i(int number, char *base);
void				ft_putnbr_base_ui(unsigned int number, const char *base);
void				ft_putnbr_base_l(long number, const char *base);
void				ft_putnbr_base_ul(unsigned long number, const char *base);
void				ft_putnbr_base_ll(long long number, const char *base);
void				ft_putnbr_base_ull(unsigned long long number,
						const char *base);

void				ft_putnbr_precise_f(float number, int precision);
void				ft_putnbr_f(float number);

void				ft_putnbr_precise_d(double number, int precision);
void				ft_putnbr_d(double number);

void				ft_putnbr_precise_ld(long double number, int precision);
void				ft_putnbr_ld(long double number);

void				ft_puthex_uppercase(unsigned int number);
void				ft_puthex_lowercase(unsigned int number);

unsigned int		ft_count_digits(int number);
unsigned int		ft_count_digits_i(int number);
unsigned int		ft_count_digits_ui(unsigned int number);
unsigned int		ft_count_digits_ul(unsigned long number);
unsigned int		ft_count_digits_ull(unsigned long long number);

unsigned int		ft_count_digits_hex_ui(unsigned int number);
unsigned int		ft_count_digits_hex_ul(unsigned long number);

unsigned int		ft_count_chars_i(int number);
unsigned int		ft_count_chars_ui(unsigned int number);

unsigned int		ft_count_chars_f(float number, int precision);
unsigned int		ft_count_digits_f(float number, int precision);

unsigned int		ft_count_chars_d(double number, int precision);
unsigned int		ft_count_digits_d(double number, int precision);

unsigned int		ft_count_chars_ld(long double number, int precision);
unsigned int		ft_count_digits_ld(long double number, int precision);

char				*ft_skip_digits(char *str);
char				*ft_skip_whitespace(char *str);
char				*ft_skip_plus_or_minus(char *str);
char				*ft_skip_commas(char *str);

char				*ft_skip_number(char *str);
char				*ft_skip_int(char *str);
char				*ft_skip_int_commas(char *str);
char				*ft_skip_int_whitespace(char *str);

char				*ft_skip_float(char *str);
char				*ft_skip_float_commas(char *str);
char				*ft_skip_float_whitespace(char *str);

/******************************************************************************\
 * LENGTH STRINGS
\******************************************************************************/

typedef struct s_lstr
{
	char			*ptr;
	size_t			len;
}					t_lstr;

void				ft_init_lstr(t_lstr *lstr);
void				ft_free_lstr(t_lstr *free_me);
void				ft_del_lstr(t_lstr **delete_me);

void				ft_join_lstr_str(t_lstr *lstr, char *str, size_t str_size);

/******************************************************************************\
 * LINKED LISTS
\******************************************************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstnew_safe(void *content);

void				ft_lst_trim(t_list *node);
void				ft_lst_trim_next(t_list *node);

void				ft_lst_init(t_list **list, void *content);
void				ft_lst_init_safe(t_list **list, void *content);

t_list				*ft_lstmap(t_list *node,
						void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstmap_safe(t_list *node, void *(*f)(void *));
void				ft_lstiter(t_list *node, void (*f)(void *));

t_list				*ft_lstdup(t_list *node, void (*del)(void *));
t_list				*ft_lstdup_safe(t_list *node);

t_list				*ft_lstlast(t_list *node);

int					ft_lstsize(t_list *node);

void				ft_lstadd_front(t_list **list, t_list *new);
void				ft_lst_nadd_front(t_list **list, t_list *new);

void				ft_lstadd_back(t_list **list, t_list *new);
void				ft_lst_nadd_back(t_list **list, t_list *new);

void				ft_lstdelone(t_list *node, void (*del)(void *));
void				ft_lstclear(t_list **list, void (*del)(void *));

void				ft_lst_append(t_list **list, void *content);
void				ft_lst_prepend(t_list **list, void *content);

void				ft_lst_add(t_list **list, void *content);
void				ft_lst_addf(t_list **list, void *content);
void				ft_lst_cadd_front(t_list **list, void *content);

void				ft_lst_addb(t_list **list, void *content);
void				ft_lst_cadd_back(t_list **list, void *content);

t_list				*ft_lst_pluck_first(t_list **list);

void				ft_lst_free(t_list **free_me);

/******************************************************************************\
 * DOUBLY LINKED LISTS
\******************************************************************************/

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

# define DLIST_BAD_INDEX_CODE -1

bool				ft_dlst_is_null(t_dlist **list);
bool				ft_dlst_is_empty(t_dlist **list);

bool				ft_dlst_index_out_of_bounds(t_dlist **list, int index);

t_dlist				*ft_dlstnew(void *content);
t_dlist				*ft_dlstnew_safe(void *content);

void				*ft_dlst_content(t_dlist *node);
t_dlist				*ft_dlst_prev(t_dlist *node);
t_dlist				*ft_dlst_next(t_dlist *node);

void				ft_dlst_trim(t_dlist *node);
void				ft_dlst_trim_next(t_dlist *node);
void				ft_dlst_trim_prev(t_dlist *node);

void				ft_dlst_init(t_dlist **list, void *content);
void				ft_dlst_init_safe(t_dlist **list, void *content);

t_dlist				*ft_dlstmap(t_dlist *node,
						void *(*f)(void *),
						void (*del)(void *));
t_dlist				*ft_dlstmap_safe(t_dlist *node, void *(*f)(void *));
void				ft_dlstiter(t_dlist *node, void (*f)(void *));

t_dlist				*ft_dlstdup(t_dlist *node, void (*del)(void *));
t_dlist				*ft_dlstdup_safe(t_dlist *node);

t_dlist				*ft_dlstlast(t_dlist *node);
t_dlist				*ft_dlst_get(t_dlist **list, int index);
t_dlist				*ft_dlst_get_safe(t_dlist **list, int index);

int					ft_dlstsize(t_dlist *node);
int					ft_dlst_max_index(t_dlist *node);

void				ft_dlstadd_front(t_dlist **list, t_dlist *new);
void				ft_dlst_nadd_front(t_dlist **list, t_dlist *new);

void				ft_dlstadd_back(t_dlist **list, t_dlist *new);
void				ft_dlst_nadd_back(t_dlist **list, t_dlist *new);

void				ft_dlstdelone(t_dlist *node, void (*del)(void *));
void				ft_dlstclear(t_dlist **list, void (*del)(void *));

void				ft_dlst_append(t_dlist **list, void *content);
void				ft_dlst_prepend(t_dlist **list, void *content);

void				ft_dlst_add(t_dlist **list, void *content);
void				ft_dlst_addf(t_dlist **list, void *content);
void				ft_dlst_cadd_front(t_dlist **list, void *content);

void				ft_dlst_add_lalloc(t_list **lalloc,
						t_dlist **list,
						void *content);
void				ft_dlst_addf_lalloc(t_list **lalloc,
						t_dlist **list,
						void *content);
void				ft_dlst_cadd_front_lalloc(t_list **lalloc,
						t_dlist **list,
						void *content);

void				ft_dlst_addb(t_dlist **list, void *content);
void				ft_dlst_cadd_back(t_dlist **list, void *content);

void				ft_dlst_addb_lalloc(t_list **lalloc,
						t_dlist **list,
						void *content);
void				ft_dlst_cadd_back_lalloc(t_list **lalloc,
						t_dlist **list,
						void *content);

t_dlist				*ft_dlst_find(t_dlist **list, t_dlist *node);
bool				ft_dlst_node_in_list(t_dlist **list, t_dlist *node);

t_dlist				*ft_dlst_pluck(t_dlist **list, int index);
t_dlist				*ft_dlst_pluck_safe(t_dlist **list, int index);
t_dlist				*ft_dlst_pluck_first(t_dlist **list);
t_dlist				*ft_dlst_pluck_last(t_dlist **list);
t_dlist				*ft_dlst_pluck_node(t_dlist **list, t_dlist *target);

void				ft_dlst_link(t_dlist *previous,
						t_dlist *node,
						t_dlist	*next);
void				ft_dlst_delink(t_dlist *node);

void				ft_dlst_free(t_dlist **free_me);

/******************************************************************************\
 * LISTED MEMORY ALLOCATION
\******************************************************************************/

void				*ft_lalloc(t_list **lalloc, size_t size);
void				*ft_clalloc(t_list **lalloc, size_t nmemb, size_t size);

void				ft_add_lalloc(t_list **lalloc, void *allocated_address);
void				ft_add_lalloc_array(t_list **lalloc,
						void **allocated_array);
void				ft_free_lalloc(t_list **free_me);

char				*ft_strdup_lalloc(t_list **lalloc, const char *s);

/******************************************************************************\
 * STRING ARRAYS
\******************************************************************************/

char				**ft_strarr_new(size_t length);

size_t				ft_strarr_len(char **strings);
size_t				ft_strarr_size(char **strings);

char				**ft_strarr_dup(char **clone_me);
char				**ft_strarr_dup_shallow(char **copy_me);

void				ft_strarr_cut(char **cut_me);
void				ft_strarr_cutn(char **cut_me, int n);

void				ft_free_strarr(char **free_me);

void				ft_put_strarr(char **strings);
void				ft_put_strarr_inline(char **strings);

bool				ft_str_in_strarr(char **haystack, char *needle);
char				*ft_find_in_strarr(char **haystack, char *needle);

char				*ft_join_strarr(char **strarr);

void				ft_add_lalloc_strarr(t_list **lalloc,
						char **allocated_strarr);

/******************************************************************************\
 * DICTIONARIES
\******************************************************************************/

typedef struct s_dict
{
	char		*key;
	void		*value;
}				t_dict;

void				*ft_dict_find(const t_dict **dictionary, char *key);

/******************************************************************************\
 * FT_GET_NEXT_LINE
\******************************************************************************/

# define GNL_FOUND_LINEBREAK 1
# define GNL_FOUND_EOF 0
# define GNL_ERROR -1

int					ft_get_next_line(int fd, char **line);
int					ft_gnl(int fd, char **line);
int					ft_gnl_or_die(int fd, char **line);

void				ft_dump_fd(int fd);
void				ft_dump_stdin(void);

/******************************************************************************\
 * FT_PRINTF
\******************************************************************************/

int					ft_printf(const char *format, ...);

void				ft_debug(const char *format, ...);
void				ft_bdebug(bool debug, const char *format, ...);

/******************************************************************************\
 * SHELL
\******************************************************************************/

void				ft_clear(void);

/******************************************************************************\
 * COLORS
\******************************************************************************/

/* Black, Red, Green, Yellow, Blue, Purple, Cyan, White */
# define BK "\001\033[0;30m\002"
# define R "\001\033[0;31m\002"
# define G "\001\033[0;32m\002"
# define Y "\001\033[0;33m\002"
# define B "\001\033[0;34m\002"
# define P "\001\033[0;35m\002"
# define C "\001\033[0;36m\002"
# define W "\001\033[0;37m\002"

/* Bold */
# define BKB "\001\033[1;30m\002"
# define RB "\001\033[1;31m\002"
# define GB "\001\033[1;32m\002"
# define YB "\001\033[1;33m\002"
# define BB "\001\033[1;34m\002"
# define PB "\001\033[1;35m\002"
# define CB "\001\033[1;36m\002"
# define WB "\001\033[1;37m\002"

/* Reset Color */
# define RC "\001\033[0m\002"

void				ft_black(char *str);
void				ft_black_endl(char *str);
void				ft_blackb(char *str);
void				ft_blackb_endl(char *str);

void				ft_red(char *str);
void				ft_red_endl(char *str);
void				ft_redb(char *str);
void				ft_redb_endl(char *str);

void				ft_green(char *str);
void				ft_green_endl(char *str);
void				ft_greenb(char *str);
void				ft_greenb_endl(char *str);

void				ft_yellow(char *str);
void				ft_yellow_endl(char *str);
void				ft_yellowb(char *str);
void				ft_yellowb_endl(char *str);

void				ft_blue(char *str);
void				ft_blue_endl(char *str);
void				ft_blueb(char *str);
void				ft_blueb_endl(char *str);

void				ft_purple(char *str);
void				ft_purple_endl(char *str);
void				ft_purpleb(char *str);
void				ft_purpleb_endl(char *str);

void				ft_cyan(char *str);
void				ft_cyan_endl(char *str);
void				ft_cyanb(char *str);
void				ft_cyanb_endl(char *str);

void				ft_white(char *str);
void				ft_white_endl(char *str);
void				ft_whiteb(char *str);
void				ft_whiteb_endl(char *str);

#endif
