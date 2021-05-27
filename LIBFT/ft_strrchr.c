/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:19:02 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 19:19:05 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = strlen(str);
	if ((char)c == '\0')
		return ((char *)str + i);
	while (i-- > 0)
	{
		if (*(str + i) == c)
			return ((char *)str + i);
	}
	return (NULL);
}
/*int main (void) 
{
   const char str[] = "holaestamos";
   const char ch = 'b';

   printf("%s\n", strrchr(str, ch));
   printf("%s\n", ft_strrchr(str, ch));
   return(0);
}
*/