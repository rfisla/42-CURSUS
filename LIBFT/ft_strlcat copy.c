/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:30:34 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/24 16:35:14 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t  i;
    size_t  j;

    i = 0;
    j = 0;

    while (dst[i] != '\0' && i < size)
        i++;
    while (src[j] != '\0' && (i + j + 1) < size)
    {
        dst[i] = src[j];
        j++;
    }
    if (i < size)
        dst[i + j] = '\0';
    return (i + strlen(src));
}
/*int main (void)
{
	char c[] = "hola";
    const char d[] = "adios";
	printf("%zu\n", ft_strlcat(c, d, 10));
    printf("%s\n", c);
	printf("%lu\n", strlcat(c, d , 10));

}
*/
