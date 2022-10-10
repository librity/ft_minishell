/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_raw_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:00:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/08 13:48:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	attr_is_empty(t_termios *attr)
{
	int		i;
	char	*cast;

	i = sizeof(t_termios);
	cast = (char *)attr;
	while (i--)
	{
		if (*cast++ != '\0')
			return (false);
	}
	return (true);
}

void	enable_tty_raw_mode(void)
{
	t_termios	raw_tty_flags;
	int			set_result;

	if (attr_is_empty(original_tty_attr()))
		die(TTY_EMPTY_ATTR_ERR);
	raw_tty_flags = *original_tty_attr();
	raw_tty_flags.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw_tty_flags.c_lflag &= ~(ICANON | ISIG | IEXTEN);
	set_result = tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_tty_flags);
	if (set_result == -1)
		die(TTY_SET_ATTR_ERR);
}

void	disable_tty_raw_mode(void)
{
	int	set_result;

	if (attr_is_empty(original_tty_attr()))
		die(TTY_EMPTY_ATTR_ERR);
	set_result = tcsetattr(
			STDIN_FILENO,
			TCSAFLUSH,
			original_tty_attr()
			);
	if (set_result == -1)
		die(TTY_RESTORE_ATTR_ERR);
}
