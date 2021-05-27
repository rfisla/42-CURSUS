/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:35:44 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/17 18:04:35 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (n > 0)
	{
		*str1++ = *str2++;
		n--;
	}
	return (dest);
}
/*int main () {
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   printf("%p\n", ft_memcpy(dest, src, 7));
   printf("%s\n", dest);
   printf("%p\n", memcpy(dest, src, 7));
   return(0);
}
*/
