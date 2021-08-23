/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:14:01 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/23 18:18:30 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	ft_errors(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nInvalid PID\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nOverflow atoi\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nUnable to send signal\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error\nBad arguments for server\n", 2);
	exit(1);
}
