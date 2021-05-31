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

/*Compares the first (at most) n bytes of s1 and s2. It returns an integer less 
than, equal to, or greater than zero if s1 is found, respectively, to be less 
than, to match, orbe greater than s2.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char )s1[i] - (unsigned char)s2[i]);
}
/*int main(void)
{
    char s1[]= "test\200";
    char s2[]= "test\0";
    printf("%d\n", ft_strncmp(s1,s2,6));
    printf("%d\n", strncmp(s1,s2,6));
}
*/
