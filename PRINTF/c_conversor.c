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

#include "ft_printf.h"

void    filling_width (int amount, t_printf *tab)
{
    if (tab->zero)
    {
        while (amount-- > 0)
            tab->lenght += write (1, "0", 1);
    }
    else
    {
        while (amount-- > 0)
            tab->lenght += write (1, ' ', 1);
    }
}

void    c_conversor (t_printf *tab)
{
    char    *str;
    char    c;

    c = va_arg(tab->args, int);
    str = &c;

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
