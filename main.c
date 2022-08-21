/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/21 00:55:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	initialize(int argc, char **argv, char **envp)
{
	initialize_control(argc, argv, envp);
}

static void	repl(void)
{
	lex("ls -la ..");
	lex("ls -la .. | cat -e | wc -l");
	lex("infile   < tr a '   ' |   tr ' ' x > outfile");
	lex("infile   < tr a \"   \" |   tr \" \" x > outfile");
	lex("infile   < tr a \"   \" |   tr \' \' x > outfile");
	lex("infile   < tr a \"   \' |   tr \' \" x > outfile");
	lex("infile   < tr a   \'  \"   \' |   tr \' \"     \' x > outfile");
	lex("infile   < tr a   \'  \"   \' |   tr \' \"      x > outfile");
	lex("inf'ile");
	lex("MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; ./minshell");
}

static void	cleanup(void)
{
	free_memory();
}

int	main(int argc, char **argv, char **envp)
{
	initialize(argc, argv, envp);
	repl();
	cleanup();
	return (EXIT_SUCCESS);
}
