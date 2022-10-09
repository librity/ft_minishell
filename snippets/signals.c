/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:40:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/08 21:33:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc signals.c -lreadline && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

// Exemplo de uma função que seta os sinais recebidos pelo sistema.
void init_sigaction(struct sigaction *action, void (*handler)(int), int sig)
{
	action->sa_handler = handler;
	action->sa_flags = SA_RESTART;
	sigemptyset(&action->sa_mask);
	sigaction(sig, action, NULL);
}

void sighandler_interrupt(int signal)
{
	printf("sighandler_int: %d\n", signal);
}

int main(void)
{
	struct sigaction action;

	// seta a função handler_int para quando recebermos um SIGINT.
	init_sigaction(&action, sighandler_interrupt, SIGINT);
	// aconteceu um evento Control + C, então o sistema captura esse evento e manda para a sigaction, e a sigaction manda para a função handler_int. Que foi setada no nosso programa.

	// aqui não setamos função nenhuma pois usamos a flag SIG_IGN || SIG_IGN = ignore o signal.
	init_sigaction(&action, SIG_IGN, SIGQUIT);
	// aconteceu um evento Control + ] (quit), então o sistema captura esse evento e manda para a sigaction, e a sigaction manda para a função SIG-IGNORE

	// Configure readline to auto-complete paths when the tab key is hit.
	rl_bind_key('\t', rl_complete);

	while (1)
	{
		// Display prompt and read input
		char *input = readline("prompt> ");

		// Check for EOF.
		if (!input)
			break;

		// Add input to readline history.
		add_history(input);

		// Do stuff...

		// Free buffer that was allocated by readline
		free(input);
	}
	return 0;
}
