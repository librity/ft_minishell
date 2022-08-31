/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:30:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 17:38:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int main(void)
{
	set_line_cmd("ls> out");
	lex();
	set_line_cmd("ls -la ..");
	lex();
	set_line_cmd("ls -la .. | cat -e | wc -l");
	lex();
	set_line_cmd("infile   < tr a '   ' |   tr ' ' x > outfile");
	lex();
	set_line_cmd("infile   < tr a \"   \" |   tr \" \" x > outfile");
	lex();
	set_line_cmd("infile   < tr a \"   \" |   tr \' \' x > outfile");
	lex();
	set_line_cmd("infile   < tr a \"   \' |   tr \' \" x > outfile");
	lex();
	set_line_cmd("infile   < tr a   \'  \"   \' |   tr \' \"     \' x > outfile");
	lex();
	set_line_cmd("infile   < tr a   \'  \"   \' |   tr \' \"      x > outfile");
	lex();
	set_line_cmd("inf'ile");
	lex();
	set_line_cmd("MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; 	set_line_cmd(./minshell");
	lex();
	set_line_cmd(".gitignore < tr ex ' X' | tr pi 'P ' > outfile");
	lex();
}
