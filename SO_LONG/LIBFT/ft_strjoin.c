/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:58:31 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/24 18:05:56 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Concatenates two strings. */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newchain;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	newchain = (char *)malloc (sizeof(char) * \
				 (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newchain)
		return (NULL);
	size1 = 0;
	while (s1[size1] != '\0')
	{
		newchain[size1] = s1[size1];
		size1++;
	}
	size2 = 0;
	while (s2[size2] != '\0')
		newchain[size1++] = s2[size2++];
	newchain[size1] = '\0';
	//free((void *)s1);
	return (newchain);
}
