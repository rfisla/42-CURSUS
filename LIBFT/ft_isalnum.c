/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:04:25 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/24 16:04:27 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* checks for an alphanumeric character; it is equivalent to 
 *(isalpha(c) || isdigit(c)) */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
