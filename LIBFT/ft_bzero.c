/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:11:04 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/17 17:34:55 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Erases the data in the n bytes of the memory starting at the location 
 *pointed to by s, by writing zeros (bytes containing '\0') to that area.*/

#include "libft.h"
void	*ft_bzero (void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*(ptr++) = '\0';
		n--;
	}
	return (s);
}
