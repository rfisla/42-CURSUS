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
/* Copies up to size - 1 characters from the NUL-terminated string src to dst, 
 * NUL-terminating the result.*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (*src)
		len = ft_strlen(src);
	if (size == 0)
	{
		while (src[i])
			i++;
	}
	if (*dst && size != 0)
	{
		while (i < len && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (len);
}
