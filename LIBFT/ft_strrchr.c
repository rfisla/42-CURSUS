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
/* Returns a pointer to the last occurrence of the char c in the string s. */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	while (i-- > 0)
	{
		if (*(str + i) == (unsigned char)c)
			return ((char *)str + i);
	}
	return ((char *) NULL);
}
