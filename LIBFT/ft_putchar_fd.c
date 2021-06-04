/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:05:04 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 18:05:19 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Escribe el carácter ’c’ sobre el descriptor de fichero proporcionado. */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
