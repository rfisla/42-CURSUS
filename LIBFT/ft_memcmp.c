/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:04:02 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 18:22:29 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while ((ptr2[i] != '\0') && (i < n))
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	if ((ptr2[i] == '\0') && (i < n))
		return (ptr1[i] - ptr2[i]);
	return (0);
}
/*int main () 
{
   const char str[] = "1234567";
   const char ch[] = "1234967";

   printf("%d\n", memcmp(str, ch , 7));
   printf("%d\n", ft_memcmp(str, ch , 7));

   return(0);
}
*/
