/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:53:57 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/25 15:24:28 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	byte_constructor(int c)
{
	static int	i;
	static int	byte;

	if (c == SIGUSR2)
		byte += 1 << (7 - i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(byte, 1);
		if (byte == '\0')
			ft_putchar_fd('\n', 1);
		i = 0;
		byte = 0;
	}
}
