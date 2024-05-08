/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 04:41:52 by asodor            #+#    #+#             */
/*   Updated: 2024/05/05 06:15:58 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
		ft_putchar(n + 48);
}

long	ft_mini_atoi(char *s)
{
	int		i;
	long	r;

	i = 0;
	r = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		r = r * 10;
		r = r + s[i] - '0';
		i++;
	}
	return (r);
}
