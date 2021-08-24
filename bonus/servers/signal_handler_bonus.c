/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:53:57 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/24 22:52:20 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static t_transmit	g_trs;

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

void	byte_constructor(int c)
{
	g_trs.msg += ((c & 1) << g_trs.size);
	g_trs.size++;
	if (g_trs.size == 7)
	{
		ft_putchar_fd(g_trs.msg, 1);
		if (!g_trs.msg)
			ft_putchar_fd('\n', 1);
		g_trs.msg = 0;
		g_trs.size = 0;
	}
}

void	init_signal(void)
{
	signal(SIGUSR1, byte_constructor);
	signal(SIGUSR2, byte_constructor);
	pause();
}
