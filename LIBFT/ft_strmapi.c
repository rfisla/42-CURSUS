#include "libft.h"

/*Aplica cadena cadena de las la función ’f’ a cada carácter de la 
de de caracteres ’s’ para crear una nueva de caracteres (con malloc (3)) 
que resulte aplicaciones sucesivas de ’f’.*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newchain;
	int		i;

	i = 0;
	newchain = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!newchain || !s || !f)
		return (NULL);
	while (s[i])
	{
		newchain[i] = f(i, s[i]);
		i++;
	}
	newchain[i] = '\0';
	return (newchain);
}
