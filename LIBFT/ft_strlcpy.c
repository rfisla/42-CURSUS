/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:54:40 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/24 17:12:42 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	if (*src)
		len = ft_strlen(src);
	if (*dst && size != 0)
	{
		i = 0;
		while (i < len && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
/*#include <bsd/string.h>
int main (void)
{
	char c[15];
    const char d[] = "lorem";
	printf("%zu\n", ft_strlcpy(c, d, 10));
    printf("%s\n", c);
	printf("%lu\n", strlcpy(c, d , 10));

}
*/
