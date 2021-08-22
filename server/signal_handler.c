/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:53:57 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/21 19:32:27 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	msg_handler(char msg)
{
	static char	buffer[1024];
	static int	index = 0;

	ft_putnbr_base(msg, "01");
/* 	ft_putnbr_fd((int)msg, 1); */
	ft_putchar_fd('\n', 1);
	if (index == 0)
		ft_bzero(buffer, 1024);
	buffer[index] = msg;
	index++;
	if (msg == '\0' || index == 1024)
	{
		ft_putstr_fd(buffer, 1);
		index = 0;
	}
}

void	char_constructor(char c)
{
	static int	i = 0;
	static int	j = 7;
	static char	msg = '\0';

	/* ft_putnbr_fd((int)c, 1);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1); */
	if (i < 7)
		msg = (msg + c) << j;
	else
	{
		msg = msg + c;
		msg_handler(msg);
	}
	i++;
	j--;
	if (i == 8)
	{
		i = 0;
		msg = '\0';
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		char_constructor((char)0);
	else
		char_constructor((char)1);
}

void	init_signal(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
}
