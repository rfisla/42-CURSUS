/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:11:41 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 21:15:27 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while ((s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s2[i] == '\0') && (i < n))
		return (s1[i] - s2[i]);
	return (0);
}
/*int main(void)
{
    char s1[]= "test\200";
    char s2[]= "test\0";
    printf("%d\n", ft_strncmp(s1,s2,5));
    printf("%d\n", strncmp(s1,s2,5));
}
*/