/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:09:53 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/27 18:24:10 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	get_line(t_data *data);
void	get_tokens(t_data *data);

void	init_data(t_minishell *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	printf("\e[1;1H\e[2J");
}

int init_shell(int argc, char **argv, char **envp)
{
	t_minishell	tmp;
	t_data		data;

	init_data(&tmp, argc, argv, envp);
	while(1)
	{
		get_tokens(&data);
		free(data.line_cmd);
		printf("\n");
	}
	return (0);
}

void	get_tokens(t_data *data)
{
	char	path[MAX_PATH];
	char	*tmp;

	getcwd(path, MAX_PATH);
	tmp = ft_strjoin(path, "$ ");
	data->line_cmd = ft_strdup("");
	while (!*data->line_cmd)
	{
		free(data->line_cmd);
		printf(GREEN "%s " WHITE "in ", getenv("USER"));
		data->line_cmd = readline(tmp);
		if (!ft_strncmp(data->line_cmd, "exit", 6))
			exit(0);
	}
	add_history(data->line_cmd);
	//tokenize(data->line_cmd, data);
	free(tmp);
}
