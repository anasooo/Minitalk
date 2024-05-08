/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:59:55 by asodor            #+#    #+#             */
/*   Updated: 2024/05/06 06:13:19 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	character;
	static int	bits_received;

	(void)context;
	bits_received++;
	character = character << 1;
	if (sig == SIGUSR1)
		character = character | 1;
	if (bits_received == 8)
	{
		if (character == 0)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &character, 1);
		bits_received = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr((long)pid);
	ft_putstr("\n");
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) != 0
		|| sigaction(SIGUSR2, &sa, NULL) != 0)
		return (1);
	while (1)
	{
		pause();
	}
	return (0);
}
