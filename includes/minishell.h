/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:42:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 17:39:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>

# include <defines.h>
# include <errors.h>
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
bool			initialize_envht(void);
void			destroy_envht(void);
char			**envht_to_envp(void);

bool			envht_insert(char *key, char *value);
char			*envht_get(char *key);
bool			envht_delete(char *key);

char			*last_exit(void);
bool			initialize_last_exit(void);
bool			destroy_last_exit(void);
bool			set_last_exit(int exit_status);

t_list			**lalloc(void);
void			free_lalloc(void);

/******************************************************************************\
 * LEXER
\******************************************************************************/

char			**lex(char *input);
char			**tokenize(char *input);

char			**tokenize_variable(char *declaration);

/******************************************************************************\
 * EXPANDER
\******************************************************************************/

char			*expand(char *input);

char			**isolate_variables(char *input);

/******************************************************************************\
 * SYNTAX
\******************************************************************************/

bool			has_valid_quotes(char *line);

bool			is_valid_variable(char *variable);

bool			tokens_are_valid(char **tokens);

bool			tokens_have_semicolon(char **tokens);
bool			tokens_have_backslash(char **tokens);
bool			has_valid_truncate(char **tokens);
bool			has_valid_append(char **tokens);

bool			is_valid_filename(char *filename);

bool			has_metachar(char *str);
bool			is_metachar(char c);

bool			has_specialchar(char *str);
bool			is_specialchar(char c);

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
char			**ht_to_strarr(t_hash_table *table);

void			ht_insert_in_index(t_hash_table *table,
					char *key,
					char *value,
					int index);
bool			ht_delete_in_index(t_hash_table *table, char *key, int index);

t_ht_item		*ht_new_item(char *key, char *value);
void			ht_destroy_item(t_ht_item **item);
char			*ht_item_to_string(t_ht_item *item);

int				ht_get_index(char *message);
t_dlist			**ht_get_index_list(t_hash_table *table, int index);

/******************************************************************************\
 * STRINGS
\******************************************************************************/

char			*skip_single_quotes(char *line);
char			*skip_double_quotes(char *line);
char			*skip_quotes(char *token);

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
bool			at_dollar(char *line);
bool			at_truncate(char *line);
bool			at_append(char *line);
bool			at_read_file(char *line);
bool			at_heredoc(char *line);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void			initialize_shell(int argc, char **argv, char **envp);
void			cleanup_shell(void);

void			die(char *error_message);

void			print_error(char *message);
void			print_warning(char *message);

#endif
