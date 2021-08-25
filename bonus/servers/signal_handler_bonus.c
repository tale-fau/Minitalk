/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:53:57 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/25 01:45:39 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

unsigned char reverse_bits(unsigned char b)
{
	unsigned char	r = 0;
	unsigned		byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void	byte_constructor(int c)
{
	static int	i;
	static int	byte;

	if (c == SIGUSR2)
		byte += 1 << (31 - i);
	i++;
	if (i == 32)
	{
		ft_putchar_fd(byte, 1);
		if (byte == 0)
			ft_putstr_fd("\nMessage fully received.\n", 1);
		i = 0;
		byte = 0;
	}
}
