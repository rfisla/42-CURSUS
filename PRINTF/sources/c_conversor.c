/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:56:32 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/04 15:56:36 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	c_conversor(t_printf *tab, int choice)
{
	char	*str;
	char	c;

	if (choice == 1)
		c = '%';
	else
		c = va_arg(tab->args, int);
	str = &c;
	if (tab->zero && tab->dash)
		tab->zero = 0;
	if (tab->dash)
	{
		tab->lenght += write(1, str, 1);
		filling_width(tab->width - 1, tab);
	}
	else
	{
		filling_width(tab->width - 1, tab);
		tab->lenght += write(1, str, 1);
	}
}
