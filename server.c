/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:23:29 by asodor            #+#    #+#             */
/*   Updated: 2024/05/05 06:32:04 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static char	character;
	static int	bits_received;

	bits_received++;
	character = character << 1;
	if (sig == SIGUSR1)
		character = character | 1;
	if (bits_received == 8)
	{
		write(1, &character, 1);
		bits_received = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction		sa;
	pid_t					pid;

	pid = getpid();
	ft_putstr("Server PID : ");
	ft_putnbr((long)pid);
	ft_putstr("\n");
	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
