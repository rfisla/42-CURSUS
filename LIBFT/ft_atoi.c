/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:16:09 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/19 21:16:12 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Converts the initial portion of the string pointed to by nptr to int*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	mult;
	int	number;

	i = 0;
	mult = 1;
	if (nptr[0] == '\0')
		return (i);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while ((nptr[i] == '-' || nptr[i] == '+') && (nptr[i + 1] >= '0'
			&& nptr[i + 1] <= '9'))
	{
		if (nptr[i] == '-')
			mult *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	return (number * mult);
}
