/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:49:37 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 17:49:47 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*  Realiza una iteración sobre la lista ’lst’ y aplica
 *  la función ’f’ al contenido de cada elemento. */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst && f)
	{
		while (lst)
		{
			tmp = lst->next;
			f(lst->content);
			lst = tmp;
		}
	}
}
