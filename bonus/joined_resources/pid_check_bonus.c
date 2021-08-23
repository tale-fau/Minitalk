/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:23:36 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/23 16:55:24 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	pid_check(char *pid)
{
	int	i;

	i = -1;
	while (pid[++i])
		if (ft_isdigit(pid[i]) == 1)
			ft_errors(2);
	if (ft_atoi(pid) > MAX_PID && ft_atoi(pid) < 1)
		ft_errors(2);
	return (0);
}
