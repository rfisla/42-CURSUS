/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:38:03 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/24 17:38:48 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Returns the substring of the given string at the given start position with 
 * the given length (or smaller if the length of the original string is less 
 * than start + length, or length is bigger than MAXSTRINGLEN).*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newchain;
	size_t	i;

	if (!s)
		return (NULL);
	newchain = (char *)malloc (sizeof(*newchain) * (len + 1));
	if (!newchain)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		newchain[i] = s[start];
		start++;
		i++;
	}
	newchain[i] = '\0';
	return (newchain);
}
