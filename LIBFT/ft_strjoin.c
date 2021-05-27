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

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newchain;
	size_t	size1;
	size_t	size2;

	newchain = (char *)malloc (sizeof(*s1 + *s2) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!newchain)
		return (NULL);
	size1 = 0;
	while (*s1)
	{
		newchain[size1] = s1[size1];
		size1++;
	}
	size2 = 0;
	while (*s2)
		newchain[size1++] = s2[size2++];
	newchain[size1] = '\0';
	return (newchain);
}
int main(void)
{
    char const a[] = "12345";
	char const b[] = "67890";
    printf("%s\n", ft_strjoin(a,b));
}
/*se puede hacer facilmente con strcpy && strcat*/
