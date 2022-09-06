/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoutes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:12:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 19:13:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*skip_single_quotes(char *line)
{
	return (ft_strchr(++line, SINGLE_QUOTE));
}

char	*skip_double_quotes(char *line)
{
	return (ft_strchr(++line, DOUBLE_QUOTE));
}
