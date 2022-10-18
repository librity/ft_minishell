# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 21:58:14 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/10/18 06:29:00 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes
TESTS_PATH = ./tests

CC = cc
# CC = clang
# CC = clang-12

CC_STRICT = $(CC) \
	$(CCF_INCLUDES) \
	$(CCF_STRICT)

CC_FULL = $(CC_STRICT) \
	$(CCF_DEBUG)
#	$(CCF_LEAK) \
#	$(CCF_OPTIMIZATION) \

CCF_INCLUDES = -I $(INCLUDES_PATH)
CCF_STRICT = -Wall -Wextra -Werror
CCF_OPTIMIZATION = -O3
CCF_DEBUG = -g
CCF_LEAK = -fsanitize=leak

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

HEADER_FILE = libft.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

#SOURCES = $(wildcard $(SOURCES_PATH)/**/*.c) $(wildcard $(SOURCES_PATH)/*.c)
SOURCES = ./sources/length_strings/ft_free_lstr.c ./sources/length_strings/ft_init_lstr.c ./sources/length_strings/ft_join_lstr_str.c ./sources/length_strings/ft_del_lstr.c ./sources/doubly_linked_lists/ft_dlst_cadd_front.c ./sources/doubly_linked_lists/ft_dlstdelone.c ./sources/doubly_linked_lists/ft_dlstnew.c ./sources/doubly_linked_lists/ft_dlstmap.c ./sources/doubly_linked_lists/ft_dlst_max_index.c ./sources/doubly_linked_lists/ft_dlst_content.c ./sources/doubly_linked_lists/ft_dlst_trim.c ./sources/doubly_linked_lists/ft_dlstadd_front.c ./sources/doubly_linked_lists/ft_dlstdup.c ./sources/doubly_linked_lists/ft_dlst_get.c ./sources/doubly_linked_lists/ft_dlst_addb.c ./sources/doubly_linked_lists/ft_dlst_pluck_first.c ./sources/doubly_linked_lists/ft_dlst_index_out_of_bounds.c ./sources/doubly_linked_lists/ft_dlst_link.c ./sources/doubly_linked_lists/ft_dlst_cadd_back_lalloc.c ./sources/doubly_linked_lists/ft_dlst_prepend.c ./sources/doubly_linked_lists/ft_dlstiter.c ./sources/doubly_linked_lists/ft_dlst_find.c ./sources/doubly_linked_lists/ft_dlst_prev.c ./sources/doubly_linked_lists/ft_dlstnew_safe.c ./sources/doubly_linked_lists/ft_dlst_trim_next.c ./sources/doubly_linked_lists/ft_dlst_next.c ./sources/doubly_linked_lists/ft_dlst_pluck_last.c ./sources/doubly_linked_lists/ft_dlst_cadd_front_lalloc.c ./sources/doubly_linked_lists/ft_dlst_is_empty.c ./sources/doubly_linked_lists/ft_dlstdup_safe.c ./sources/doubly_linked_lists/ft_dlst_add.c ./sources/doubly_linked_lists/ft_dlst_init.c ./sources/doubly_linked_lists/ft_dlst_addf.c ./sources/doubly_linked_lists/ft_dlst_get_safe.c ./sources/doubly_linked_lists/ft_dlst_is_null.c ./sources/doubly_linked_lists/ft_dlst_pluck.c ./sources/doubly_linked_lists/ft_dlstadd_back.c ./sources/doubly_linked_lists/ft_dlst_free.c ./sources/doubly_linked_lists/ft_dlst_pluck_node.c ./sources/doubly_linked_lists/ft_dlst_nadd_back.c ./sources/doubly_linked_lists/ft_dlst_delink.c ./sources/doubly_linked_lists/ft_dlst_append.c ./sources/doubly_linked_lists/ft_dlstclear.c ./sources/doubly_linked_lists/ft_dlst_init_safe.c ./sources/doubly_linked_lists/ft_dlst_node_in_list.c ./sources/doubly_linked_lists/ft_dlstmap_safe.c ./sources/doubly_linked_lists/ft_dlst_pluck_safe.c ./sources/doubly_linked_lists/ft_dlst_nadd_front.c ./sources/doubly_linked_lists/ft_dlstsize.c ./sources/doubly_linked_lists/ft_dlst_trim_prev.c ./sources/doubly_linked_lists/ft_dlst_addf_lalloc.c ./sources/doubly_linked_lists/ft_dlst_cadd_back.c ./sources/doubly_linked_lists/ft_dlstlast.c ./sources/doubly_linked_lists/ft_dlst_add_lalloc.c ./sources/doubly_linked_lists/ft_dlst_addb_lalloc.c ./sources/shell/ft_clear.c ./sources/arrays/ft_arr_size.c ./sources/arrays/ft_free_arr.c ./sources/arrays/ft_arr_len.c ./sources/print_numbers/ft_putnbr_base_ui.c ./sources/print_numbers/ft_count_digits_ul.c ./sources/print_numbers/ft_count_digits_d.c ./sources/print_numbers/ft_puthex_uppercase.c ./sources/print_numbers/ft_putnbr_ll.c ./sources/print_numbers/ft_skip_int.c ./sources/print_numbers/ft_skip_commas.c ./sources/print_numbers/ft_count_digits_f.c ./sources/print_numbers/ft_count_digits_ull.c ./sources/print_numbers/ft_putnbr_precise_f.c ./sources/print_numbers/ft_skip_int_whitespace.c ./sources/print_numbers/ft_putnbr_ld.c ./sources/print_numbers/ft_skip_float_whitespace.c ./sources/print_numbers/ft_is_valid_base.c ./sources/print_numbers/ft_skip_number.c ./sources/print_numbers/ft_count_digits_ui.c ./sources/print_numbers/ft_putnbr_base.c ./sources/print_numbers/ft_skip_float.c ./sources/print_numbers/ft_skip_int_commas.c ./sources/print_numbers/ft_count_digits_ld.c ./sources/print_numbers/ft_putnbr_base_l.c ./sources/print_numbers/ft_count_chars_i.c ./sources/print_numbers/ft_putnbr_base_ll.c ./sources/print_numbers/ft_putnbr_i.c ./sources/print_numbers/ft_putnbr_fd.c ./sources/print_numbers/ft_putnbr_precise_d.c ./sources/print_numbers/ft_count_digits_hex_ul.c ./sources/print_numbers/ft_skip_plus_or_minus.c ./sources/print_numbers/ft_count_chars_ld.c ./sources/print_numbers/ft_count_chars_d.c ./sources/print_numbers/ft_putnbr_l.c ./sources/print_numbers/ft_skip_digits.c ./sources/print_numbers/ft_putnbr_ui.c ./sources/print_numbers/ft_count_digits.c ./sources/print_numbers/ft_putnbr_base_ull.c ./sources/print_numbers/ft_putnbr_f.c ./sources/print_numbers/ft_count_chars_ui.c ./sources/print_numbers/ft_putnbr_base_ul.c ./sources/print_numbers/ft_putnbr.c ./sources/print_numbers/ft_skip_float_commas.c ./sources/print_numbers/ft_count_digits_hex_ui.c ./sources/print_numbers/ft_putnbr_ull.c ./sources/print_numbers/ft_puthex_lowercase.c ./sources/print_numbers/ft_putnbr_base_i.c ./sources/print_numbers/ft_putnbr_d.c ./sources/print_numbers/ft_putnbr_precise_ld.c ./sources/print_numbers/ft_count_digits_i.c ./sources/print_numbers/ft_count_chars_f.c ./sources/print_numbers/ft_skip_whitespace.c ./sources/print_numbers/ft_putnbr_ul.c ./sources/chars/ft_toupper.c ./sources/chars/ft_islower.c ./sources/chars/ft_is_whitespace.c ./sources/chars/ft_isupper.c ./sources/chars/ft_isdigit.c ./sources/chars/ft_is_decimal_char.c ./sources/chars/ft_is_plus_or_minus.c ./sources/chars/ft_isalnum.c ./sources/chars/ft_isalpha.c ./sources/chars/ft_tolower.c ./sources/chars/ft_isprint.c ./sources/chars/ft_isascii.c ./sources/memory/ft_srealloc.c ./sources/memory/ft_memset.c ./sources/memory/ft_calloc.c ./sources/memory/ft_memchr.c ./sources/memory/ft_memmove.c ./sources/memory/ft_memccpy.c ./sources/memory/ft_realloc.c ./sources/memory/ft_memcmp.c ./sources/memory/ft_del.c ./sources/memory/ft_memcpy.c ./sources/memory/ft_salloc.c ./sources/memory/ft_bzero.c ./sources/memory/ft_scalloc.c ./sources/math/ft_factorial.c ./sources/math/ft_max_d.c ./sources/math/ft_map_clamped_i.c ./sources/math/ft_abs_ld.c ./sources/math/ft_lerp_wsteps_d.c ./sources/math/ft_sqrt.c ./sources/math/ft_swap_i.c ./sources/math/ft_swap.c ./sources/math/ft_map_i.c ./sources/math/ft_map_clamped_d.c ./sources/math/ft_abs_d.c ./sources/math/ft_sqrt_i.c ./sources/math/ft_pow.c ./sources/math/ft_clamp_d.c ./sources/math/ft_map_d.c ./sources/math/ft_lerp_precise_d.c ./sources/math/ft_div_mod.c ./sources/math/ft_div_mod_i.c ./sources/math/ft_abs.c ./sources/math/ft_abs_f.c ./sources/math/ft_lerp_i.c ./sources/math/ft_pow_i.c ./sources/math/ft_min_i.c ./sources/math/ft_clamp_i.c ./sources/math/ft_lerp_d.c ./sources/math/ft_min_d.c ./sources/math/ft_lerp_precise_i.c ./sources/math/ft_fibonacci.c ./sources/math/ft_pow_ll.c ./sources/math/ft_max_i.c ./sources/math/ft_lerp_wsteps_i.c ./sources/math/ft_abs_i.c ./sources/print_strings/ft_putchar_fd.c ./sources/print_strings/ft_endl.c ./sources/print_strings/ft_putendl_fd.c ./sources/print_strings/ft_putchar.c ./sources/print_strings/ft_putstr_up_to.c ./sources/print_strings/ft_puts.c ./sources/print_strings/ft_putendl.c ./sources/print_strings/ft_putstr_fd.c ./sources/print_strings/ft_putstr.c ./sources/colors/ft_purple.c ./sources/colors/ft_yellow.c ./sources/colors/ft_blue.c ./sources/colors/ft_white.c ./sources/colors/ft_red.c ./sources/colors/ft_green.c ./sources/colors/ft_cyan.c ./sources/colors/ft_black.c ./sources/linked_lists/ft_lstmap.c ./sources/linked_lists/ft_lst_free.c ./sources/linked_lists/ft_lstdup.c ./sources/linked_lists/ft_lst_pluck_first.c ./sources/linked_lists/ft_lst_init_safe.c ./sources/linked_lists/ft_lst_prepend.c ./sources/linked_lists/ft_lstnew_safe.c ./sources/linked_lists/ft_lstmap_safe.c ./sources/linked_lists/ft_lstlast.c ./sources/linked_lists/ft_lstdup_safe.c ./sources/linked_lists/ft_lst_init.c ./sources/linked_lists/ft_lst_addf.c ./sources/linked_lists/ft_lstadd_back.c ./sources/linked_lists/ft_lstdelone.c ./sources/linked_lists/ft_lst_trim_next.c ./sources/linked_lists/ft_lst_trim.c ./sources/linked_lists/ft_lst_nadd_back.c ./sources/linked_lists/ft_lstadd_front.c ./sources/linked_lists/ft_lst_addb.c ./sources/linked_lists/ft_lstclear.c ./sources/linked_lists/ft_lst_nadd_front.c ./sources/linked_lists/ft_lstiter.c ./sources/linked_lists/ft_lstsize.c ./sources/linked_lists/ft_lst_cadd_back.c ./sources/linked_lists/ft_lst_append.c ./sources/linked_lists/ft_lst_add.c ./sources/linked_lists/ft_lst_cadd_front.c ./sources/linked_lists/ft_lstnew.c ./sources/lalloc/ft_add_lalloc_array.c ./sources/lalloc/ft_clalloc.c ./sources/lalloc/ft_free_lalloc.c ./sources/lalloc/ft_add_lalloc.c ./sources/lalloc/ft_strdup_lalloc.c ./sources/lalloc/ft_lalloc.c ./sources/random/ft_prand_range.c ./sources/random/ft_prand.c ./sources/booleans/unless.c ./sources/strings/ft_strsize.c ./sources/strings/ft_strtrim.c ./sources/strings/ft_substr.c ./sources/strings/ft_strlcpy.c ./sources/strings/ft_strnew.c ./sources/strings/ft_has_chars.c ./sources/strings/ft_strmapi.c ./sources/strings/ft_strjoin_free.c ./sources/strings/ft_strlcat.c ./sources/strings/ft_strjoin_free_free.c ./sources/strings/ft_strchr.c ./sources/strings/ft_has_char.c ./sources/strings/ft_strdel.c ./sources/strings/ft_is_empty_str.c ./sources/strings/ft_strlen.c ./sources/strings/ft_strdup.c ./sources/strings/ft_split.c ./sources/strings/ft_strnchr.c ./sources/strings/ft_strnstr.c ./sources/strings/ft_streq.c ./sources/strings/ft_strjoin.c ./sources/strings/ft_strrchr.c ./sources/strings/ft_join_size_size.c ./sources/strings/ft_strcpy.c ./sources/strings/ft_strjoin_del.c ./sources/strings/ft_starts_with.c ./sources/strings/ft_strjoin_del_del.c ./sources/strings/ft_strncmp.c ./sources/strings/ft_strdup_null.c ./sources/string_to_number/ft_atold.c ./sources/string_to_number/ft_atoui.c ./sources/string_to_number/ft_atoull.c ./sources/string_to_number/ft_str_is_int.c ./sources/string_to_number/ft_atoui_strict.c ./sources/string_to_number/ft_atof.c ./sources/string_to_number/ft_str_is_uint.c ./sources/string_to_number/ft_atoll.c ./sources/string_to_number/ft_atoi.c ./sources/string_to_number/ft_atoul.c ./sources/string_to_number/ft_atol.c ./sources/string_arrays/ft_find_in_strarr.c ./sources/string_arrays/ft_strarr_len.c ./sources/string_arrays/ft_join_strarr.c ./sources/string_arrays/ft_str_in_strarr.c ./sources/string_arrays/ft_put_strarr_inline.c ./sources/string_arrays/ft_strarr_dup.c ./sources/string_arrays/ft_add_lalloc_strarr.c ./sources/string_arrays/ft_free_strarr.c ./sources/string_arrays/ft_strarr_new.c ./sources/string_arrays/ft_strarr_size.c ./sources/string_arrays/ft_put_strarr.c ./sources/string_arrays/ft_strarr_dup_shallow.c ./sources/string_arrays/ft_strarr_cut.c ./sources/string_arrays/ft_strarr_cutn.c ./sources/bits/ft_inspect_cstr.c ./sources/bits/ft_print_bits_ull.c ./sources/bits/ft_switch_bit_endianess_ui32.c ./sources/bits/ft_print_bits_uc.c ./sources/bits/ft_print_bits.c ./sources/bits/ft_print_bits_c.c ./sources/bits/ft_print_bits_ui.c ./sources/bits/ft_rotate_left_i.c ./sources/bits/ft_print_bits_ul.c ./sources/bits/ft_rotate_left_ui32.c ./sources/bits/ft_print_bits_i.c ./sources/bits/ft_switch_byte_endianess_ui32.c ./sources/bits/ft_hexdump.c ./sources/bits/ft_rotate_right_i.c ./sources/bits/ft_rotate_right_ui32.c ./sources/errors/ft_die.c ./sources/number_to_string/ft_ui_to_buffer_base.c ./sources/number_to_string/ft_i_to_buffer.c ./sources/number_to_string/ft_precise_dtoa.c ./sources/number_to_string/ft_precise_ftoa.c ./sources/number_to_string/ft_uc_to_buffer_lchex.c ./sources/number_to_string/ft_ui_to_buffer.c ./sources/number_to_string/ft_ltoa.c ./sources/number_to_string/ft_dtoa.c ./sources/number_to_string/ft_precise_ldtoa.c ./sources/number_to_string/ft_ui_to_buffer_lchex.c ./sources/number_to_string/ft_ftoa.c ./sources/number_to_string/ft_uc_to_buffer_base.c ./sources/number_to_string/ft_itoa.c ./sources/number_to_string/ft_ldtoa.c ./sources/number_to_string/ft_uitoa.c ./sources/get_next_line/ft_gnl_or_die.c ./sources/get_next_line/ft_dump_stdin.c ./sources/get_next_line/ft_get_next_line.c ./sources/get_next_line/ft_gnl.c ./sources/get_next_line/ft_dump_fd.c ./sources/dictionaries/ft_dict_find.c ./sources/printf/pf_print_s.c ./sources/printf/ft_debug.c ./sources/printf/pf_handled_lf.c ./sources/printf/pf_handle_minus_sign.c ./sources/printf/pf_parse_flags.c ./sources/printf/pf_handled_hex.c ./sources/printf/pf_print_lf.c ./sources/printf/pf_handled_s.c ./sources/printf/pf_print_c.c ./sources/printf/pf_handled_p.c ./sources/printf/pf_parse_wildcars.c ./sources/printf/pf_handled_c.c ./sources/printf/pf_handled_int.c ./sources/printf/pf_print_u.c ./sources/printf/pf_print_p.c ./sources/printf/pf_handled_no_conversion.c ./sources/printf/pf_vprintf.c ./sources/printf/ft_bdebug.c ./sources/printf/pf_initializers.c ./sources/printf/pf_handled_percent.c ./sources/printf/pf_print_percent.c ./sources/printf/pf_handled_f.c ./sources/printf/pf_print_f.c ./sources/printf/pf_print_hex.c ./sources/printf/ft_printf.c ./sources/printf/pf_print_int.c ./sources/printf/pf_handled_u.c 

OBJECTS = $(patsubst $(SOURCES_PATH)/%.c, $(OBJECTS_PATH)/%.o, $(SOURCES))
OBJECT_DIRECTORIES = $(sort $(dir $(OBJECTS)))

################################################################################
# REQUIRED
################################################################################

all: $(NAME)

$(NAME): $(HEADER) $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(NAME) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(CC_FULL) -c -o $@ $<

re: fclean all

################################################################################
# DIRS
################################################################################

dirs: $(OBJECTS_PATH) $(OBJECT_DIRECTORIES)

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

$(OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

################################################################################
# CLEAN
################################################################################

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

################################################################################
# TESTS
################################################################################

test:
	$(MAKE_EXTERNAL) $(TESTS_PATH)

test_clean:
	$(MAKE_EXTERNAL) $(TESTS_PATH) fclean

################################################################################
# EXAMPLE
################################################################################

EXAMPLE_MAIN = examples/example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

example: $(NAME)
	$(CC_FULL) $(EXAMPLE_MAIN) $(NAME)
	$(EXECUTE_EXAMPLE)

vgexample: $(NAME)
	$(CC_STRICT) $(CCF_DEBUG) $(EXAMPLE_MAIN) $(NAME)
	valgrind $(EXECUTE_EXAMPLE)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

CC_VG = $(CC) \
	$(CCF_INCLUDES) \
	$(CCF_STRICT)

VG = valgrind
VG_FLAGS = --leak-check=full --show-leak-kinds=all --trace-children=yes
VG_LOG = valgrind_leaks.log
VG_LOG_FLAGS = --log-file=$(VG_LOG) \
	--leak-check=full \
	--show-leak-kinds=all \
	--trace-children=yes \
	--track-origins=yes \
	--verbose

VG_TARGET = ./a.out

vg: vg_build
	$(VG) $(VG_FLAGS) $(VG_TARGET)

vglog: vg_build
	$(VG) $(VG_LOG_FLAGS) $(VG_TARGET)

vg_build: $(NAME)
	$(CC_VG) \
		$(EXAMPLE_MAIN) \
		$(NAME)

vglog_clean: fclean
	$(REMOVE) $(VG_LOG)

################################################################################
# MISC
################################################################################

norm:
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "update"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

dump_sources:
	@echo =========== SOURCES ===========
	@echo "SOURCES = $(SOURCES)"
	@echo ===============================

################################################################################
# PHONY
################################################################################

.PHONY: all re \
	dirs \
	clean fclean \
\
	test_clean test \
	example example_clean \
	vg vglog vg_build vglog_clean \
\
	norm git gitm dump_sources

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
Bk = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BkB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC	= \033[0m
