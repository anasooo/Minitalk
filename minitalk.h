/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 04:34:03 by asodor            #+#    #+#             */
/*   Updated: 2024/05/05 06:17:29 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

void	ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr(long n);
long	ft_mini_atoi(char *s);

#endif
