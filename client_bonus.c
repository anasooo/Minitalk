/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:59:36 by asodor            #+#    #+#             */
/*   Updated: 2024/05/05 06:11:08 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Message received\n");
}

void	send_char(int pid, char c)
{
	int	shift;
	int	i;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i);
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	signal(SIGUSR1, signal_handler);
	if (ac != 3)
		return (ft_putstr("Enter a valid args"), 0);
	pid = ft_mini_atoi(av[1]);
	if (pid == 0)
		return (ft_putstr("Invalid PID\n"), 0);
	i = 0;
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\0');
}
