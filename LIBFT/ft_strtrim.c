/* Reserva memoria (con malloc(3)) y devuelve la cadena de caracteres que es 
una copia de ’s1’, sin los caracteres indicados en el ’set’ al principio y
al final de la cadena de caracteres.*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newchain;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
	{
		end--;
	}
	newchain = ft_substr ((char *)s1, 0, end + 1 );
	return (newchain);
}
