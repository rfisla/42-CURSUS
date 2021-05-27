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
/*int main () 
{
   const char src[50] = "http://www.tu3torialspoint.com";
   char dest[50];
   printf("%p\n", ft_memccpy(dest, src, '3' ,50));
   printf("%s\n",dest);
   printf("%p\n", memccpy(dest, src, '3' ,50));
   return(0);
}
*/