/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 20:27:05 by tale-fau          #+#    #+#             */
/*   Updated: 2021/01/08 17:05:05 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	if ((ret = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		ret[j] = s2[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
