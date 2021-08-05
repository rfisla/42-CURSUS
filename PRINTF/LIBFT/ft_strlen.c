/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:23:03 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 18:30:44 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Returns the lenght of s. */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}