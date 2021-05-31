/*Escribe el carácter ’c’ sobre el descriptor de fichero proporcionado*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
