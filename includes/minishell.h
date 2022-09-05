/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:42:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 22:22:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <defines.h>
# include <warnings.h>
# include <structs.h>

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_minishell		*c(void);
void			initialize_control(int argc, char **argv, char **envp);
void			deinitialize_control(void);

bool			debug(void);
void			set_debug(bool verbose);

int				argc(void);
char			**argv(void);
char			**envp(void);

t_hash_table	*envht(void);
void			initilize_envht(void);
void			destroy_envht(void);

t_list			**lalloc(void);
void			free_lalloc(void);

/******************************************************************************\
 * LEXER
\******************************************************************************/

char			**lex(char *input);
char			**tokenize(char *input);

char			**tokenize_variable(char *declaration);

char			*skip_single_quotes(char *line);
char			*skip_double_quotes(char *line);

char			*insert_around_two(char *line);
char			*insert_around_one(char *line);
char			*insert_delimiter(char *line);

void			insert_delimiter_before(char *buffer);
void			insert_delimiter_after(char *buffer);
void			insert_delimiter_around(char *buffer);
void			insert_delimiter_around_2(char *buffer);

void			strbuff_insert_before(char *buffer, char insert_me);
void			strbuff_insert_after(char *buffer, char insert_me);
void			strbuff_insert_around(char *buffer, char insert_me);
void			strbuff_insert_around_2(char *buffer, char insert_me);

bool			at_single_quote(char *line);
bool			at_double_quote(char *line);
bool			at_pipe(char *line);
bool			at_space(char *line);
bool			at_truncate(char *line);
bool			at_append(char *line);
bool			at_read_file(char *line);
bool			at_heredoc(char *line);

/******************************************************************************\
 * CRYPTO
\******************************************************************************/

uint32_t		*md5_little_endian(void *message, size_t msg_length);
uint32_t		*md5_big_endian(void *message, size_t msg_length);
uint32_t		md5_sum(char *message);

char			*md5_hex(char *message);
char			*md5_digest_to_hex(uint32_t *digest);

void			inspect_md5(char *message, uint32_t *digest);
void			print_md5(uint32_t *digest);

uint32_t		*md5(void *message, size_t msg_length);
void			md5_pad_message(t_md5 *m);
void			md5_calculate_digest(t_md5 *m);
void			md5_scramble_chunk_digest(uint32_t i,
					uint32_t words[16],
					uint32_t _[4]);

uint32_t		*md5_rotations(void);
uint32_t		*md5_sines(void);
uint32_t		*md5_initial_digest(void);

/******************************************************************************\
 * HAST TABLE
\******************************************************************************/

t_hash_table	*ht_new(void);
void			ht_destroy(t_hash_table **table);

bool			ht_insert(t_hash_table *table,
					char *key, char *value);
char			*ht_get(t_hash_table *table, char *key);
bool			ht_delete(t_hash_table *table, char *key);
bool			ht_insert_strarr(t_hash_table *table, char **strings);

void			ht_insert_in_index(t_hash_table *table,
					char *key,
					char *value,
					int index);
bool			ht_delete_in_index(t_hash_table *table, char *key, int index);

t_ht_item		*ht_new_item(char *key, char *value);
void			ht_destroy_item(t_ht_item **item);

int				ht_get_index(char *message);
t_dlist			**ht_get_index_list(t_hash_table *table, int index);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void			initialize_shell(int argc, char **argv, char **envp);

void			print_error(char *message);
void			print_warning(char *message);

#endif
