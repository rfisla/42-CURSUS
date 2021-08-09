/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:57:55 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/06 17:57:56 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf	*ft_reset_tab(t_printf *tab)
{
	tab->width = 0;
	tab->precission = 0;
	tab->hash = 0;
	tab->zero = 0;
	tab->dash = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->point = 0;
	tab->sign = 0;
	tab->ox = 0;
	return (tab);
}

void	printing_sign (t_printf *tab)
{
	if (tab->sign)
		tab->lenght += write (1, "-", 1);
	else if (tab->plus)
		tab->lenght += write(1, "+", 1);
	if (tab->ox == 1 || tab->hash == 1)
		tab->lenght += write(1, "0x", 2);
}

void	filling_width (int amount, t_printf *tab)
{
	if (tab->zero)
	{
		if (tab->sign || tab->plus)
			while (amount-- > 1)
				tab->lenght += write (1, "0", 1);
		else
			while (amount-- > 0)
				tab->lenght += write (1, "0", 1);
	}
	else
	{
		if (tab->sign || tab->plus)
			while (amount-- > 1)
				tab->lenght += write (1, " ", 1);
		else
			while (amount-- > 0)
				tab->lenght += write (1, " ", 1);
	}
}

void	exception_negatives(t_printf *tab, int number)
{
	if (number == -2147483648)
	{
		tab->sign = 0;
		tab->plus = 0;
	}
	else if (number < 0 && number > -2147483648)
		tab->sign = 1;
}

void	print_space(t_printf *tab, long number)
{
	if (tab->space && number >= 0 && !tab->plus && \
		tab->precission >= tab->width)
		tab->lenght += write(1, " ", 1);
}
