/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/07 15:50:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	initialize(int argc, char **argv, char **envp)
{
	char	**env_vars;

	initialize_shell(argc, argv, envp);
	env_vars = envht_to_envp();
	ft_put_strarr(env_vars);
	ft_free_strarr(env_vars);
}

static void	run_shell(void)
{
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
