/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:23:50 by tale-fau          #+#    #+#             */
/*   Updated: 2020/08/07 09:23:43 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

long int		ft_base_len(char *base)
{
	long int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int				ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_base_len(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	long int	n;

	n = nbr;
	if (ft_check_base(base) == 0)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= ft_base_len(base))
	{
		ft_putnbr_base(n / ft_base_len(base), base);
		ft_putnbr_base(n % ft_base_len(base), base);
	}
	if (n >= 0 && n < ft_base_len(base))
	{
		ft_putchar(base[n]);
	}
}
