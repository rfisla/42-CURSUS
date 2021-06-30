/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:25:36 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/16 16:25:40 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t		count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}


char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char) c)
			return ((char *) str);
		str++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) str);
	return ((char *) NULL);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newchain;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	newchain = (char *)malloc (sizeof(*s1 + *s2) * \
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
	free((void *)s1); //This line avoid many leaks that i couldn´t fix
	return (newchain);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

