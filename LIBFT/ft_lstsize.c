/* Cuenta el número de elementos de la lista.*/
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst->next != NULL)
	{
		count++;
		lst = lst->next;
	}
	if (lst->next == NULL)
		count++;
	return (count);
}
