/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:15:04 by tale-fau          #+#    #+#             */
/*   Updated: 2021/01/07 23:22:48 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if ((new = (t_list *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
