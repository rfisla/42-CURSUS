/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:40:09 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 17:33:34 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (d > s)
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	else if (s > d)
		ft_memcpy(dest, src, n);
	return (dest);
}
/*int main (void) 
{
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   printf("%p\n", ft_memmove(dest, src, 50));
   printf("%s\n", dest);
   printf("%p\n", memmove(dest, src, 50));
   return(0);
}
*/
