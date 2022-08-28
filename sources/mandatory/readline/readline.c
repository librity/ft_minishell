/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:00:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/28 17:56:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	get_tokens(void)
{
	char	path[MAX_PATH];
	char	*tmp;

	getcwd(path, MAX_PATH);
	tmp = ft_strjoin(path, "$ ");
	set_line_cmd(ft_strdup(""));
	while (!*line_cmd())
	{
		free(line_cmd());
		printf(GB "%s " WB "in ", getenv("USER"));
		set_line_cmd(readline(tmp));
		if (ft_streq(line_cmd(), "exit"))
			exit(0);
	}
	add_history(line_cmd());
	c()->tokens = lex();
	free(tmp);
}

int	init_shell(void)
{
	printf("\e[1;1H\e[2J");
	while (1)
	{
		get_tokens();
		// Expansor
		// Syntax Validator
		// Trimmer
		// Parser
		// Executor
		free(line_cmd());
		printf("\n");
	}
	return (0);
}


