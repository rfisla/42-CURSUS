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
