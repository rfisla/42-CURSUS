/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:04:53 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/24 16:04:55 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* checks if c is a 7-bit unsigned char value that fits into the ASCII set */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
