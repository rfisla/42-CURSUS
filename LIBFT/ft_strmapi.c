/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:16:06 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/04 18:16:13 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Aplica cadena cadena de las la función ’f’ a cada carácter de la 
 * de de caracteres ’s’ para crear una nueva de caracteres (con malloc (3)) 
 * que resulte aplicaciones sucesivas de ’f’.*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newchain;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	newchain = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!newchain)
		return (NULL);
	while (s[i])
	{
		newchain[i] = f(i, s[i]);
		i++;
	}
	newchain[i] = '\0';
	return (newchain);
}
