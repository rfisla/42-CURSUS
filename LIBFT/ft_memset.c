/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:06:53 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/17 17:09:44 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* The memset() function fills the first n bytes of the memory area pointed to
 * by s with the constant byte c. */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		*(ptr++) = (unsigned char)c;
	}
	return (s);
}
