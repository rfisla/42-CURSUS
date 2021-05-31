/*Escribe el entero ’n’ sobre el descriptor de
fichero proporcionado. */

#include "libft.h"

void	ft_putnbr_fd (int n, int fd)
{
	char	*number;

	number = ft_itoa(n);
	while (*number)
		write (fd, number++, 1);
}
