/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:40:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 15:52:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc signals.c -lreadline && ./a.out

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

bool debug = false;

// Exemplo de uma função que seta os sinais recebidos pelo sistema.
void set_signal_hook(struct sigaction *action, void (*handler)(int), int sig)
{
	action->sa_handler = handler;
	action->sa_flags = SA_RESTART;
	sigemptyset(&action->sa_mask);
	sigaction(sig, action, NULL);
}

void handle_interrupt_signal(int signal)
{
	if (debug)
		printf("DEBUG: handle_interrupt_signal: signal: %d\n", signal);
	else
		printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void handle_kill_signal(int signal)
{
	if (debug)
		printf("DEBUG: handle_kill_signal: signal: %d\n", signal);
	exit(42);
}

int main(void)
{
	struct sigaction action;

	// seta a função handler_int para quando recebermos um SIGINT.
	set_signal_hook(&action, handle_interrupt_signal, SIGINT);
	// aconteceu um evento Control + C, então o sistema captura esse evento e manda para a sigaction, e a sigaction manda para a função handler_int. Que foi setada no nosso programa.

	// aqui não setamos função nenhuma pois usamos a flag SIG_IGN || SIG_IGN = ignore o signal.
	set_signal_hook(&action, SIG_IGN, SIGQUIT);
	// aconteceu um evento Control + ] (quit), então o sistema captura esse evento e manda para a sigaction, e a sigaction manda para a função SIG-IGNORE

	set_signal_hook(&action, handle_kill_signal, SIGKILL);

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
		if (strlen(input) > 0)
			add_history(input);

		// Do stuff...

		// Free buffer that was allocated by readline
		free(input);
	}

	rl_clear_history();
	return 0;
}
