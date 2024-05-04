/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:59:55 by asodor            #+#    #+#             */
/*   Updated: 2024/05/04 02:36:24 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static char character = 0;
    static int bits_received = 0;
    static int client_pid;

    (void)context;
//    if ((client_pid != info->si_pid && bits_received != 0))
//    {
//	    bits_received = 0;
//	    character = 0;
//  }
    bits_received++;
    character = character << 1;
    if (sig == SIGUSR1)
	    character = character | 1;

    if (bits_received == 8) {
	    if (character == 0)
		    kill(info->si_pid, SIGUSR1);
	    else 
		    write(1, &character, 1);
        bits_received = 0;
        character = 0;
    }
    client_pid = info->si_pid;
}

int main()
{
	struct sigaction	sa;

	printf("Server PID: %d\n", getpid());
	// Setup signal handler
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) != 0 || sigaction(SIGUSR2, &sa, NULL) != 0)
		return (1);
	while (1)
	{
		pause();
	}
	return 0;  // Although unreachable, it's good practice
}

