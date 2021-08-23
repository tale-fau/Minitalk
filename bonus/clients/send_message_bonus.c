/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:48:39 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/23 18:08:43 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) != 0)
		ft_errors(4);
}

int	bit_equals_one(int binary, char c)
{
	return ((binary & c) == binary);
}

void	reset_variables(int *j, int *binary)
{
	*j = 0;
	*binary = 1;
}

void	send_print_signal(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

void	send_message(char *message, int pid)
{
	int	i;
	int	j;
	int	binary;

	i = 0;
	binary = 1;
	j = 0;
	while (message[i])
	{
		while (j < 8)
		{
			if (bit_equals_one(binary, message[i]))
				send_signal(pid, SIGUSR2);
			else
				send_signal(pid, SIGUSR1);
			usleep(100);
			binary <<= 1;
			j++;
		}
		reset_variables(&j, &binary);
		i++;
	}
	send_print_signal(pid);
}
