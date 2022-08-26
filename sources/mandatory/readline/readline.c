/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:09:53 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/26 20:11:39 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_shell(char **line);

void	init_data(t_minishell *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
}

int main(int argc, char **argv, char **envp)
{
	t_minishell data;
	char		*line;

	init_data(&data, argc, argv, envp);
	printf("\e[1;1H\e[2J");
	while(1)
	{
		init_shell(&line);
	}
}

void	init_shell(char **line)
{
	char	path[MAX_PATH];
	char	*tmp;

	printf(GREEN "%s " WHITE "in ", getenv("USER"));
	getcwd(path, MAX_PATH);
	tmp = ft_strjoin(path, "$ ");
	printf("line = %s\n", *line);
	while (!*line)
		*line = readline(tmp);
	free(tmp);
}
