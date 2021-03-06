/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:53:57 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/25 15:25:31 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

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
