/* #1. La dirección del puntero al primer elemento de
la lista. #2. La dirección del puntero al elemento que hay
que añadir a la lista.Añade el elemento ’new’ al principio de la lista. */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
