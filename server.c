/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:23:29 by asodor            #+#    #+#             */
/*   Updated: 2024/05/02 19:18:32 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int sig)
{
    static char character = 0;
    static int bits_received = 0;

    bits_received++;
    character = character << 1;
    if (sig == SIGUSR1)
	    character = character | 1;

    if (bits_received == 8) {
        write(1, &character, 1);
        bits_received = 0;
        character = 0;
    }
}

int main()
{
    struct sigaction sa;
    printf("Server PID: %d\n", getpid());
    // Setup signal handler
    sa.sa_handler = &handle_signal;
    // Register signals
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1) {
        pause();
    }

    return 0;
}

