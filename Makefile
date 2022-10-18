# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/10/17 19:27:34 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
# CC = clang
# CC = clang-12

CC_BASIC = $(CC) \
	$(CCF_INCLUDES)

CC_STRICT = $(CC_BASIC) \
	$(CCF_STRICT)

CC_FULL = $(CC_STRICT) \
	$(CCF_DEBUG)
#	$(CCF_LEAK) \
#	$(CCF_OPTIMIZATION) \

CCF_INCLUDES = -I $(LIBFT_INCLUDES) -I $(INCLUDES_PATH)
CCF_STRICT = -Wall -Wextra -Werror
CCF_OPTIMIZATION = -O3
CCF_DEBUG = -g
CCF_LEAK = -fsanitize=leak
CCF_LIBS = -lreadline

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
ARCHIVES_PATH = ./archives

LIBS_PATH = ./libs

LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INCLUDES = $(LIBFT_PATH)/includes

################################################################################
# MANDATORY
################################################################################

M_HEADER = $(INCLUDES_PATH)/minishell.h
M_ARCHIVE = $(ARCHIVES_PATH)/minishell.a

M_SOURCES_PATH = $(SOURCES_PATH)/mandatory
M_OBJECTS_PATH = $(OBJECTS_PATH)/mandatory

# M_SOURCES = $(wildcard $(M_SOURCES_PATH)/**/*.c) $(wildcard $(M_SOURCES_PATH)/*.c)
M_SOURCES = ./sources/mandatory/builtins/cd.c ./sources/mandatory/builtins/cd_change.c ./sources/mandatory/builtins/core.c ./sources/mandatory/builtins/echo.c ./sources/mandatory/builtins/env.c ./sources/mandatory/builtins/exit_atoi.c ./sources/mandatory/builtins/exit.c ./sources/mandatory/builtins/exit_status.c ./sources/mandatory/builtins/export_assignment.c ./sources/mandatory/builtins/export.c ./sources/mandatory/builtins/export_dump.c ./sources/mandatory/builtins/export_extract.c ./sources/mandatory/builtins/export_insert.c ./sources/mandatory/builtins/export_invalid.c ./sources/mandatory/builtins/help.c ./sources/mandatory/builtins/pwd.c ./sources/mandatory/builtins/unset.c ./sources/mandatory/control/arguments.c ./sources/mandatory/control/debug.c ./sources/mandatory/control/envht.c ./sources/mandatory/control/envht_interface.c ./sources/mandatory/control/ioe.c ./sources/mandatory/control/last_exit.c ./sources/mandatory/control/line_count.c ./sources/mandatory/control/memory.c ./sources/mandatory/control/original_tty_attr.c ./sources/mandatory/control/sigaction.c ./sources/mandatory/control/singleton.c ./sources/mandatory/crypto/md5.c ./sources/mandatory/crypto/md5_digest.c ./sources/mandatory/crypto/md5_endianess.c ./sources/mandatory/crypto/md5_hex.c ./sources/mandatory/crypto/md5_padding.c ./sources/mandatory/crypto/md5_print.c ./sources/mandatory/crypto/md5_scramble.c ./sources/mandatory/crypto/md5_sum.c ./sources/mandatory/crypto/md5_tables.c ./sources/mandatory/executor/builtins.c ./sources/mandatory/executor/execute.c ./sources/mandatory/executor/executors.c ./sources/mandatory/executor/exeve.c ./sources/mandatory/executor/find.c ./sources/mandatory/executor/fork_or_die.c ./sources/mandatory/executor/hdoc.c ./sources/mandatory/executor/path.c ./sources/mandatory/executor/paths.c ./sources/mandatory/executor/pipeline.c ./sources/mandatory/executor/redirections.c ./sources/mandatory/executor/sequence.c ./sources/mandatory/executor/spawn.c ./sources/mandatory/executor/spawn_multiple.c ./sources/mandatory/executor/wait.c ./sources/mandatory/expander/expand.c ./sources/mandatory/expander/expand_line.c ./sources/mandatory/expander/isolate.c ./sources/mandatory/expander/variables.c ./sources/mandatory/files/close.c ./sources/mandatory/files/dirs.c ./sources/mandatory/files/dup.c ./sources/mandatory/files/infile.c ./sources/mandatory/files/ioe.c ./sources/mandatory/files/outfiles.c ./sources/mandatory/flags/debug.c ./sources/mandatory/hash_table/core.c ./sources/mandatory/hash_table/delete.c ./sources/mandatory/hash_table/for_each.c ./sources/mandatory/hash_table/get.c ./sources/mandatory/hash_table/index.c ./sources/mandatory/hash_table/insert.c ./sources/mandatory/hash_table/insert_strarr.c ./sources/mandatory/hash_table/item.c ./sources/mandatory/hash_table/to_strarr.c ./sources/mandatory/lexer/lex.c ./sources/mandatory/lexer/operators.c ./sources/mandatory/lexer/pipes.c ./sources/mandatory/lexer/tokens.c ./sources/mandatory/lexer/variables.c ./sources/mandatory/parser/append.c ./sources/mandatory/parser/exec.c ./sources/mandatory/parser/finders.c ./sources/mandatory/parser/getters.c ./sources/mandatory/parser/heredoc.c ./sources/mandatory/parser/list.c ./sources/mandatory/parser/parse.c ./sources/mandatory/parser/parse_tokens.c ./sources/mandatory/parser/pipe.c ./sources/mandatory/parser/read_file.c ./sources/mandatory/parser/t_parse.c ./sources/mandatory/parser/truncate.c ./sources/mandatory/pipes/core.c ./sources/mandatory/pipes/file.c ./sources/mandatory/pipes/stdin.c ./sources/mandatory/pipes/stdout.c ./sources/mandatory/pipes/write.c ./sources/mandatory/prompt/core.c ./sources/mandatory/runtime/banner.c ./sources/mandatory/runtime/cleanup.c ./sources/mandatory/runtime/die.c ./sources/mandatory/runtime/initialize.c ./sources/mandatory/runtime/print.c ./sources/mandatory/runtime/quit.c ./sources/mandatory/runtime/repl.c ./sources/mandatory/signals/disable.c ./sources/mandatory/signals/fork_hooks.c ./sources/mandatory/signals/hdoc_hooks.c ./sources/mandatory/signals/set_hook.c ./sources/mandatory/signals/shell_hooks.c ./sources/mandatory/strings/delimiter.c ./sources/mandatory/strings/delimiters.c ./sources/mandatory/strings/insert.c ./sources/mandatory/strings/line_at_1.c ./sources/mandatory/strings/line_at_2.c ./sources/mandatory/strings/quoutes.c ./sources/mandatory/strings/strbuff.c ./sources/mandatory/syntax/backslash.c ./sources/mandatory/syntax/error.c ./sources/mandatory/syntax/filename.c ./sources/mandatory/syntax/heredoc.c ./sources/mandatory/syntax/line.c ./sources/mandatory/syntax/meta.c ./sources/mandatory/syntax/pipe.c ./sources/mandatory/syntax/quotes.c ./sources/mandatory/syntax/redirections.c ./sources/mandatory/syntax/semicolon.c ./sources/mandatory/syntax/tokens.c ./sources/mandatory/syntax/variables.c ./sources/mandatory/termios/tty_raw_mode.c ./sources/mandatory/trimmer/token.c ./sources/mandatory/trimmer/tokens.c ./sources/mandatory/trimmer/trim.c

M_OBJECTS = $(patsubst $(M_SOURCES_PATH)/%.c, $(M_OBJECTS_PATH)/%.o, $(M_SOURCES))
M_OBJECT_DIRECTORIES = $(sort $(dir $(M_OBJECTS)))

M_MAIN = ./main.c

M_ARCHIVES = $(M_ARCHIVE) $(LIBFT)

all: $(NAME)

$(NAME): $(LIBFT) $(M_ARCHIVE)
	$(CC_FULL) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		$(CCF_LIBS) \
		-o $(NAME)

$(M_ARCHIVE): $(M_HEADER) $(M_OBJECTS)
	$(ARCHIVE_AND_INDEX) $(M_ARCHIVE) $(M_OBJECTS)

$(M_OBJECTS_PATH)/%.o: $(M_SOURCES_PATH)/%.c
	$(CC_FULL) -c -o $@ $<

clean:
	$(REMOVE) $(M_OBJECTS)
	$(REMOVE) $(M_ARCHIVE)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

################################################################################
# DIRS
################################################################################

dirs: $(ARCHIVES_PATH) $(OBJECTS_PATH) \
	$(M_OBJECT_DIRECTORIES) $(B_OBJECT_DIRECTORIES)

$(ARCHIVES_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

$(M_OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

################################################################################
# CLEAN
################################################################################

tclean: clean_libs fclean fcleanb tests_clean example_clean vglog_clean

################################################################################
# LIBS
################################################################################

$(LIBFT):
	$(MAKE_EXTERNAL) $(LIBFT_PATH) all

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

clean_libs: libft_clean

################################################################################
# TESTS
################################################################################

CC_TEST = $(CC_BASIC) \
	$(CCF_DEBUG) \
	$(CCF_LEAK)

CC_VGTEST = $(CC_BASIC) \
	$(CCF_DEBUG)

TESTS_PATH = ./tests

TEST_SOURCES = $(wildcard $(TESTS_PATH)/**/*.c) $(wildcard $(TESTS_PATH)/*.c)

TESTS = $(patsubst $(TESTS_PATH)/%.c, $(TESTS_PATH)/%.out, $(TEST_SOURCES))
VGTESTS = $(patsubst $(TESTS_PATH)/%.c, $(TESTS_PATH)/%.vg.out, $(TEST_SOURCES))

tests: test_re $(TESTS)

test: test_re $(TESTS_PATH)/$t.out

$(TESTS_PATH)/%.out: $(TESTS_PATH)/%.c
	$(CC_TEST)\
		$< \
		$(M_ARCHIVES) \
		$(CCF_LIBS) \
		-o $@
	./$@

vgtests: test_re $(VGTESTS)

vgtest: test_re $(TESTS_PATH)/$t.vg.out

$(TESTS_PATH)/%.vg.out: $(TESTS_PATH)/%.c
	$(CC_VGTEST)\
		$< \
		$(M_ARCHIVES) \
		$(CCF_LIBS) \
		-o $@
	$(VG) $(VG_FLAGS) ./$@

test_re: re tests_clean

tests_clean:
	$(REMOVE_RECURSIVE) $(TESTS) $(VGTESTS)

################################################################################
# EXAMPLE
################################################################################

EXAMPLES_PATH = ./examples

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

example: build_example
	$(EXECUTE_EXAMPLE)

build_example: $(M_ARCHIVE)
	$(CC_FULL) \
		$(EXAMPLE_MAIN) \
		$(M_ARCHIVES)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

CC_VG = $(CC) \
	$(CCF_INCLUDES) \
	$(CCF_STRICT)

VG = valgrind

VG_FLAGS = --leak-check=full \
	--show-leak-kinds=all \
	--trace-children=yes \
	--suppressions=readline.supp

VG_LOG_FLAGS = $(VG_FLAGS) \
	--log-file=$(VG_LOG) \
	--track-origins=yes \
	--verbose
VG_LOG = valgrind_leaks.log

VG_TARGET = ./minishell

vg: vg_build
	$(VG) $(VG_FLAGS) $(VG_TARGET)

vglog: vg_build
	$(VG) $(VG_LOG_FLAGS) $(VG_TARGET)

vg_build: $(LIBFT) $(M_ARCHIVE)
	$(CC_VG) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		$(CCF_LIBS) \
		-o $(NAME)

vglog_clean: fclean
	$(REMOVE) $(VG_LOG)

################################################################################
# MISC
################################################################################

norm:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) norm
	@printf "\n$(G)=== No norminette errors found in $(LIBFT_PATH) ===$(RC)\n\n"
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"
	norminette $(M_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(M_MAIN) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "AUTOMATIC MESSAGE"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

dump_sources:
	@echo =========== MANDATORY ===========
	@echo "M_SOURCES = $(M_SOURCES)"
	@echo ============= BONUS =============
	@echo "B_SOURCES = $(B_SOURCES)"
	@echo =================================

################################################################################
# PHONY
################################################################################

.PHONY: \
all clean fclean re \
\
dirs \
\
tclean \
\
libft_clean clean_libs \
\
tests test vgtests vgtest test_re tests_clean \
\
example build_example example_clean \
\
vg vglog vg_build vglog_clean \
\
norm git gitm dump_sources

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BKB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC = \033[0m
