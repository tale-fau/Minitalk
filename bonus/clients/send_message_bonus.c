/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:48:39 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/25 01:48:48 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) != 0)
		ft_errors(4);
}

int	bit_equals_one(char c, int j)
{
	return (c >> j & 1);
}

void	send_message(char *message, int pid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= (int)ft_strlen(message))
	{
		j = 31;
		while (j >= 0)
		{
			if (bit_equals_one(message[i], j))
				send_signal(pid, SIGUSR2);
			else
				send_signal(pid, SIGUSR1);
			j--;
			usleep(100);
		}
		i++;
	}
}
