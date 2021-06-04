/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:46:18 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 19:18:39 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Returns a pointer to the first occurrence of the character c in the string s*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != c)
		str++;
	if (*str == c)
		return ((char *) str);
	return ((char *) NULL);
}
