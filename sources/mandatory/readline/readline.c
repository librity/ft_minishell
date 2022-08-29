/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:00:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/29 16:15:56 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


void	Syntax_Validator(void);

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
	verific_asp_line_cmd(line_cmd());
	add_history(line_cmd());
	c()->tokens = lex();
	free(tmp);
}

bool	verific_asp_line_cmd(char	*line)
{
	int	single;
	int	doub;

	single = 0;
	doub = 0;
	while(*line++)
	{
		if (*line == SINGLE_QUOTE && doub % 2 == 0)
			single++;
		if (*line == DOUBLE_QUOTE && single % 2 == 0)
			doub++;
	}
	if (single % 2 == 1 || doub % 2 == 1)
		return (false);
	return (true);
}

int	init_shell(void)
{
	printf("\e[1;1H\e[2J");
	while (1)
	{
		get_tokens();
		// Expansor
		Syntax_Validator();
		// Trimmer
		// Parser
		// Executor
		destroy_line_cmd();
		printf("\n");
	}
	return (0);
}

void	Syntax_Validator(void)
{
	int		index;

	index = 0;
	while(token_index(index))
	{
		if (token_index(index)[0] == SINGLE_QUOTE)
			token_edit(index, ft_strtrim(c()->tokens[index], "\'"));
		else if (token_index(index)[0] == DOUBLE_QUOTE)
			token_edit(index, ft_strtrim(c()->tokens[index], "\""));
		index++;
	}
	index = 0;
	while(token_index(index))
	{
		printf("tokens = %s\n",  token_index(index));
		index++;
	}
}
