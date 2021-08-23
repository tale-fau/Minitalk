/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:53:57 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/23 17:12:16 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

unsigned char	reverse_bits(unsigned char b)
{
	unsigned char	r;
	unsigned int	byte_len;

	r = 0;
	byte_len = 8;
	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void	msg_handler(char msg)
{
	static char	buffer[1024];
	static int	index = 0;

	if (index == 0)
		ft_bzero(buffer, 1024);
	buffer[index] = msg;
	index++;
	if (msg == '\0' || index == 1024)
	{
		if (msg == '\0')
			message_bonus();
		ft_putstr_fd(buffer, 1);
		if (msg == '\0')
			ft_putchar_fd('\n', 1);
		index = 0;
	}
}

void	char_constructor(char c)
{
	static int	i = 0;
	static char	msg = '\0';

	if (i < 7)
		msg = (msg + c) << 1;
	else
	{
		msg = msg + c;
		msg = reverse_bits(msg);
		msg_handler(msg);
	}
	i++;
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
