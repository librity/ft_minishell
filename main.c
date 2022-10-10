/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 16:16:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	initialize(int argc, char **argv, char **envp)
{
	initialize_shell(argc, argv, envp);
}

static void	run_shell(void)
{
	repl();
}

static void	cleanup(void)
{
	cleanup_shell();
}

int	main(int argc, char **argv, char **envp)
{
	initialize(argc, argv, envp);
	run_shell();
	cleanup();
	return (EXIT_SUCCESS);
}
