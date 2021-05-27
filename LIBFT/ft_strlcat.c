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
    return (i + ft_strlen(src));
}
void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}
int		main(void)
{
    char hola[11] = "a";
	ft_print_result(ft_strlcat(hola, "lorem", 15));
	write(1, "\n", 1);
	write(1, hola, 15);
    ft_print_result(strlcat(hola, "lorem", 11));
	write(1, "\n", 1);
	write(1, hola, 15);
}