/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:04:41 by tale-fau          #+#    #+#             */
/*   Updated: 2021/01/08 17:06:44 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_count(char const *s, char c)
{
	int	w_count;
	int	i;
	int	bol;

	i = 0;
	bol = 1;
	w_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			bol = 1;
		else if (bol == 1)
		{
			bol = 0;
			w_count++;
		}
		i++;
	}
	return (w_count);
}

int		ft_char_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*str_dup(char const *s, char c)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = ft_char_count(s, c) + 1;
	if ((ret = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		w_count;

	j = 0;
	i = 0;
	ret = NULL;
	if (!s)
		return (NULL);
	w_count = (ft_word_count(s, c));
	if ((ret = (char **)malloc(sizeof(char *) * (w_count + 1))) == NULL)
		return (NULL);
	while (j < w_count)
	{
		while (s[i] && s[i] == c)
			i++;
		ret[j] = str_dup(&s[i], c);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}
