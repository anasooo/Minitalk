/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:55:11 by asodor            #+#    #+#             */
/*   Updated: 2024/05/03 22:26:49 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void send_char(int pid, char c)
{
    int shift;
    int i;

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


int main(int ac, char **av)
{
    int i;

    if (ac != 3)
        return (1);
    i = 0;
    while (av[2][i])
    {
        send_char(atoi(av[1]), av[2][i]);
        i++;
    }
    send_char(atoi(av[1]), '\0');
}
