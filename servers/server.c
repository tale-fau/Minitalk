/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 18:55:32 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/23 18:34:54 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		init_signal();
		while (1)
			;
	}
	else
		ft_errors(5);
	return (0);
}
