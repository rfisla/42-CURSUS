/*   Realiza una iteración sobre la lista ’lst’ y aplica
la función ’f’ al contenido de cada elemento. Crea
una nueva lista que resulta de las aplicaciones
sucesivas de ’f’. Disponemos de la función ’del’ si
hay que elminar el contenido de algún elemento.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int	size;
	t_list	*newlst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	size = ft_lstsize(lst);
	newlst = (t_list *)malloc(sizeof(*t_list) * size + 1);
	if (!newlst)
		return (NULL);
	newlst = ft_lstiter(lst, f);
	newlst = ft_lstdelone(lst, del);
}
