/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 15:54:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	handled_too_many_args(char **tokens)
{
	char	*message;

	if (ft_strarr_len(tokens) == 1)
		return (false);
	message = ft_strdup("'");
	message = ft_strjoin_free(message, *(tokens + 1));
	message = ft_strjoin_free(message, "`: " NO_FILE_DIR_ERR);
	print_location_error(ENV, message);
	free(message);
	return (true);
}

static void	print_item(t_ht_item *item)
{
	if (item == NULL)
		return ;
	if (item->key == NULL)
		return ;
	if (item->value == NULL)
		return ;
	printf("%s=%s\n", item->key, item->value);
}

int	bi_env(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (ENV_NO_ARGS);
	if (handled_too_many_args(tokens))
		return (ENV_TOO_MANY_ARGS);
	ht_for_each(envht(), &print_item);
	return (EXIT_SUCCESS);
}
