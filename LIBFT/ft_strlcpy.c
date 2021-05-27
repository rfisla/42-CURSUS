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

	i = 0;
	if (size == 0)
	{
		while (*src)
			i++;
		return (i);
	}
	while (*src && i < size - 1)
	{
		dst[i] = src[i];
		i ++;
	}
	if (i < size)
		dst[i] = '\0';
	i++;
	while (src[i] != '\0')
		i++;
	return (i);
}

int main (void)
{
	char c[15];
    const char d[] = "lorem";
	printf("%zu\n", ft_strlcpy(c, d, 10));
    printf("%s\n", c);
	printf("%lu\n", strlcpy(c, d , 10));

}

