/*Escribe la cadena de caracteres ’s’ sobre el 
descriptor de fichero proporcionado.*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
