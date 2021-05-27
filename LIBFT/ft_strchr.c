/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:46:18 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 19:18:39 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != c)
		str++;
	if (*str == c)
		return ((char *) str);
	return ((char *) NULL);
}
/*int main () {
   const char str[] = "hols.gfg";
   const char ch = 's';

   printf("%s\n", strchr(str, ch));
   printf("%s\n", ft_strchr(str, ch));
   return(0);
}
*/