/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:27:22 by tale-fau          #+#    #+#             */
/*   Updated: 2021/01/02 12:29:09 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_size(int n)
{
	int			i;
	long int	nb;

	i = 0;
	nb = n;
	if (nb < 0)
		nb = nb * -1;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	loop(long int nb, char *ret, int size, int n)
{
	while (nb > 0)
	{
		ret[size] = (nb % 10) + 48;
		nb = nb / 10;
		size--;
	}
	if (n < 0)
		ret[0] = '-';
}

char	*if_zero(char *ret)
{
	if ((ret = (char *)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	ret[1] = '\0';
	ret[0] = '0';
	return (ret);
}

char	*ft_itoa(int n)
{
	int			sign;
	int			size;
	char		*ret;
	long int	nb;

	sign = 0;
	ret = NULL;
	nb = n;
	if (n == 0)
	{
		ret = if_zero(ret);
		return (ret);
	}
	if (n < 0)
	{
		sign = 1;
		nb = nb * -1;
	}
	size = n_size(n) + sign;
	if ((ret = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ret[size] = '\0';
	size--;
	loop(nb, ret, size, n);
	return (ret);
}
