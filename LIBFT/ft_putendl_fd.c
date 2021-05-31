/*Escribe la cadena de caracteres ’s’ sobre el descriptor de fichero 
proporcionado, seguida de un salto de línea.*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write (fd, s++, 1);
	write (fd, "\n", 1);
}
