/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:06:43 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 18:06:57 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Escribe la cadena de caracteres ’s’ sobre el 
 * descriptor de fichero proporcionado. */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
}
