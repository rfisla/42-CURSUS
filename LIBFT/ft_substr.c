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
    char    *newchain;

    if (!s)
        return(NULL);
    newchain = (char *)malloc (sizeof(*s) * (len + 1));
    if (!newchain)
        return (NULL);
    while (s[start] != '\0' && start < len)
    {
        newchain[start] = s[start];
        start++;
    }
    newchain[start] = '\0';
    return (newchain);
}

int main(void)
{
    char const a[] = "1234567890";
    printf("%p\n", ft_substr(a, 5, 3));
}
