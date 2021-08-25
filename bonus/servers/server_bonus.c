/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 18:55:32 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/25 01:21:43 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	main(void)
{
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, byte_constructor);
	signal(SIGUSR2, byte_constructor);
	while (1)
	{
		pause();
	}
	return (0);
}
