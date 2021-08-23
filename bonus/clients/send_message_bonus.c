/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:48:39 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/23 17:29:09 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) != 0)
		ft_errors(4);
}

void	reset_variables(int *j, int *binary)
{
	*j = 0;
	*binary = 1;
}

void	send_print_signal(int pid, int time)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(time);
		i++;
	}
}

void	time_set(int *time, char *message)
{
	if (ft_strlen(message) > 1000)
	{
		*time = ft_strlen(message) / 5;
		printf("time = %i\n", *time);
	}
	else
		*time = 100;
}

void	send_message(char *message, int pid)
{
	int	i;
	int	j;
	int	time;
	int	binary;

	i = 0;
	binary = 1;
	j = 0;
	time_set(&time, message);
	while (message[i])
	{
		while (j < 8)
		{
			if ((binary & message[i]) == binary)
				send_signal(pid, SIGUSR2);
			else
				send_signal(pid, SIGUSR1);
			usleep(time);
			binary <<= 1;
			j++;
		}
		reset_variables(&j, &binary);
		i++;
	}
	send_print_signal(pid, time);
}
