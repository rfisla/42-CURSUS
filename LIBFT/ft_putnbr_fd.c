/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:06:12 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 18:06:28 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Escribe el entero ’n’ sobre el descriptor de
 * fichero proporcionado. */

#include "libft.h"

void	ft_putnbr_fd (int n, int fd)
{
	char	*number;

	number = ft_itoa(n);
	while (*number)
		write (fd, number++, 1);
}
