/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:33:53 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 18:02:33 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Scans the initial n bytes of the memory area pointed to by s for the first 
 * instance of c.  Both c and the bytes of the memory area pointed to by s are 
 * interpreted as unsigned char. */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptrs;
	size_t			i;

	ptrs = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (ptrs[i] == (unsigned char)c)
			return (ptrs + i);
		i++;
	}
	return (NULL);
}
