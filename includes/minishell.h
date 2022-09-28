/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:42:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 17:25:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <sys/wait.h>

# include <defines.h>
# include <errors.h>
# include <structs.h>
# include <warnings.h>

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
int				last_exit_int(void);
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
bool			has_valid_read_file(char **tokens);
bool			has_valid_heredoc(char **tokens);

bool			has_valid_pipe(char **tokens);
char			**find_next_pipe(char **tokens);
int				count_pipes(char **tokens);

bool			is_valid_filename(char *filename);

bool			has_metachar(char *str);
bool			is_metachar(char c);

bool			has_specialchar(char *str);
bool			is_specialchar(char c);

char			**operators(void);
bool			is_operator(char *token);
char			**find_next_operator(char **tokens);

/******************************************************************************\
 * TRIMMER
\******************************************************************************/

void			trim_tokens(char **tokens);
void			trim_token(char *token);

/******************************************************************************\
 * PARSER
\******************************************************************************/

t_parse_list	*parse(char **tokens);

t_parse			*new_parse(void);
void			destroy_parse(t_parse **pnode);

t_parse			*new_exec(char **tokens);
t_parse			*new_exec_length(char **tokens, int length);
void			add_exec(t_parse_list **list, char **tokens);

void			add_pipe(t_parse_list **list);
t_parse			*new_pipe(void);
t_parse_list	*find_next_parse_pipe(t_parse_list *node);
int				count_parse_pipes(t_parse_list *node);

t_parse			*new_truncate(char *file_path);
void			add_truncate(t_parse_list **list, char *file_path);

t_parse			*new_append(char *file_path);
void			add_append(t_parse_list **list, char *file_path);

t_parse			*new_heredoc(char *file_path);
void			add_heredoc(t_parse_list **list, char *delimiter);

t_parse			*new_read_file(char *delimiter);
void			add_read_file(t_parse_list **list, char *file_path);

void			destroy_parse_list(t_parse_list **list);

char			**get_parse_tokens(t_parse_node *node);
char			*get_parse_file_path(t_parse_node *node);
char			*get_parse_delimiter(t_parse_node *node);
t_parse_type	get_parse_type(t_parse_node *node);

t_parse_node	*find_first_exec(t_parse_list *node);

/******************************************************************************\
 * EXECUTOR
\******************************************************************************/

void			execute(t_parse_list *pipeline);

bool			handled_single_builtin(t_parse_list *pipeline);
void			execute_pipeline(t_parse_list *list);

void			execute_pipe(t_parse_list *plist);
void			execute_last_pipe(t_parse_list *plist);

void			fork_handle_pipe_sequence(t_parse_list *node);
int				handle_builtin_sequence(t_parse_list *node);

void			handle_read_file(t_parse_list *node);
void			handle_heredoc(t_parse_list *node);
void			handle_truncate(t_parse_list *node);
void			handle_append(t_parse_list *node);

void			handle_fork_exec(t_parse_list *node);
int				handle_builtin_exec(t_parse_list *node);

void			execve_or_die(char **tokens);

char			*find_executable(char *command, char **paths);
char			*find_executable_or_die(char *command, char **paths);

char			**get_paths_or_die(void);

void			hdoc_to_stdin(char *delimiter);

pid_t			fork_or_die(void);

/******************************************************************************\
 * BUILTINS
\******************************************************************************/

t_builtin		find_builtin(char *name);
bool			is_builtin(char *name);
int				execute_builtin(char **tokens);

int				bi_cd(char **argv);
bool			cd_could_change_dir(char **tokens);

int				bi_echo(char **tokens);

int				bi_pwd(char **tokens);

int				bi_export(char **tokens);
bool			exp_dump(char **tokens);
typedef struct s_export
{
	char		*key;
	char		*value;
	int			status;
}				t_export;
int				exp_insert(char **tokens);
void			exp_cleanup(t_export *_ctl);
bool			exp_handled_bad_key(char **tokens, t_export *_ctl);
bool			exp_handled_no_assignment(char **tokens, t_export *_ctl);
char			*exp_extract_key(char *declaration);
char			*exp_extract_value(char *declaration);

int				bi_exit(char **tokens);

int				bi_unset(char **tokens);

int				bi_env(char **tokens);

int				bi_help(char **tokens);

/******************************************************************************\
 * FILES
\******************************************************************************/

int				close_or_die(int close_me);

int				open_infile_or_die(char *path);
int				open_file_or_die(char *path);

int				open_truncate_or_die(char *path);
int				open_append_or_die(char *path);

int				dup_or_die(int dup_me);
int				dup2_or_die(int from, int to);

void			save_ioe(t_proc_fds *ioe);
void			restore_ioe(t_proc_fds *ioe);

/******************************************************************************\
 * PIPES
\******************************************************************************/

void			pipe_or_die(int pipe_fds[2]);
void			close_pipe(int pipe_fds[2]);

void			file_to_stdin(int infile_fd);
void			stdout_to_file(int outfile_fd);

void			pipe_to_stdin(int pipe_fds[2]);
void			stdout_to_pipe(int pipe_fds[2]);

void			str_to_pipe(int pipe_fds[2], char *str);

/******************************************************************************\
 * HAST TABLE
\******************************************************************************/

t_hash_table	*ht_new(void);
void			ht_destroy(t_hash_table **table);

bool			ht_insert(t_hash_table *table, char *key, char *value);
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

void			ht_for_each(t_hash_table *table, t_ht_for_each_cb callback);

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

void			strbuff_insert(char *buffer, char insert_me);
void			strbuff_cut(char *buffer);

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

void			quit(void);

void			die(char *message);
void			die_perror(char *location, int exit_status);
void			die_full(char *location, char *message, int exit_status);

void			print_error(char *message);
void			print_location_error(char *location, char *message);
void			print_warning(char *message);

#endif
