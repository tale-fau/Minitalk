/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:41:36 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/21 19:30:49 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

# define MAX_PID	4194304

int		ft_errors(int i);
int		pid_check(char *pid);
void	send_message(char *message, int pid);
void	init_signal(void);
void	ft_putnbr_base(int nbr, char *base);

#endif