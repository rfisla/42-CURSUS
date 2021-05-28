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

/*int main(void)
{
    char const a[] = "lorem ipsum dolor sit amet";
    char	*dest = ft_substr(a, 7, 10);

    printf("%s\n", dest);
}
*/
