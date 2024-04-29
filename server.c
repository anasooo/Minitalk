/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:01:48 by asodor            #+#    #+#             */
/*   Updated: 2024/04/29 19:06:52 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <utils.h>
#include <signal.h>
#include <unistd.h>

pid_t	g_clientpid = -1;

void	receive(int n, int pid)
{
	int		shift;
	static int	i = 7;
	static char	c;

	if (i == -1 || pid != g_clientpid)
	{
		i = 7;
		c = 0;
		g_clientpid = pid;
	}
	shift = 1 << (i);
	if (n != 0)
		c = (c | shift);
	i--;
	if (i == -1)
		write (1, &c, 1);
}


void	handler(int sig, siginfo_t *info)
{
	if (sig == SIGUSR1)
		receive(1, info->si_pid);
	else
		receive(0, info->si_pid);
}

int	main(void)
{
	pid_t			pid;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_sigaction = handler;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

