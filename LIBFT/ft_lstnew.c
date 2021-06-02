/* Reserva memoria (con malloc(3)) y devuelve un nuevo
elemento. La variable ’content’ se inicializa
mediante el valor del parámetro ’content’. La
variable ’next’ se inicializa con NULL. */

#include "libft.h"

t_list	*ft_lstnew (void *content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
