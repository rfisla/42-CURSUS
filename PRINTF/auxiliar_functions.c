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

#include "ft_printf.h"

void	printing_sign (t_printf *tab)
{
	if (tab->sign)
		tab->lenght += write (1, "-", 1);
	else if (tab->plus)
		tab->lenght += write(1, "+", 1);
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
				tab->lenght += write (1, ' ', 1);
		else
			while (amount-- > 0)
				tab->lenght += write (1, ' ', 1);
	}
}
