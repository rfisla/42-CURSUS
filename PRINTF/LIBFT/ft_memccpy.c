/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:05:14 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 17:31:32 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Copies no more than n bytes from memory area src to memory area dest, 
 * stopping when the character c is found. If the memory areas overlap, the
 * results are undefined. */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (NULL);
	while (i < n)
	{
		str1[i] = str2[i];
		if (str1[i] == (unsigned char ) c)
			return ((void *)dest + i + 1);
		i++;
	}
	return (NULL);
}
