/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:53:29 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 17:53:36 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Cuenta el número de elementos de la lista.*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		count++;
		lst = lst->next;
	}
	if (lst->next == NULL)
		count++;
	return (count);
}
