/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:51:09 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 17:51:15 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Realiza una iteración sobre la lista ’lst’ y aplica la función ’f’ al 
 * contenido de cada elemento.Crea una lista que resulta de las aplicaciones
 * sucesivas de ’f’. Disponemos de la función ’del’ si hay que elminar el 
 * contenido de algún elemento.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newel;

	if (!f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newel = ft_lstnew (f(lst->content));
		if (!newel)
		{
			del(newlst->content);
			free(newlst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newel);
		lst = lst->next;
	}
	return (newlst);
}
