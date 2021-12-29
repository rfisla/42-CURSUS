/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:45:40 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 17:45:50 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*  Suprime y libera la memoria del elemento pasado como parámetro y 
 *  de todos los elementos siguientes, con ’del’ y free (3) Por último,
 *  el puntero inicial debe pasar a NULL.*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
	*lst = NULL;
}
