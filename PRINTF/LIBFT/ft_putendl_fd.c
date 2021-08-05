/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:05:42 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 18:05:56 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Escribe la cadena de caracteres ’s’ sobre el descriptor de fichero 
 * proporcionado, seguida de un salto de línea. */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
