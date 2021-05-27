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
/*int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("%p\n", ft_memchr(str, ch , strlen(str)));
   printf("%p\n", memchr(str, ch , strlen(str)));


   return(0);
}
*/
