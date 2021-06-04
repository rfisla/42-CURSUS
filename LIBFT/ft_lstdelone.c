/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:46:29 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 17:48:31 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*  #1. El elemento cuya memoria se debe liberar #2. La dirección de una 
 *  función utilizada para borrar el contenido del elemento  Libera la memoria
 *  del elemento pasado como argumento utilizando la función ’del’ y después
 *  free(3). No se debe liberar la memoria de ’next’. */

#include "libft.h"

void	ft_lstdelone (t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
