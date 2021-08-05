/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_conversor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:57:31 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/04 15:57:33 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    updating_table_i(t_printf *tab, char * str)
{
    if (tab->point)
    {
        if (tab->precission > ft_strlen(str))
            tab->zero = 1;
        if (tab->precission >= tab->width)
            tab->dash = 0;
    }
}

void    i_precission(t_printf *tab, char *nstr, int number)
{
    int diff;

    diff = 0;
    if (tab->precission && tab->precission > ft_strlen(nstr))
        diff = tab->precission - ft_strlen(nstr);
    if (tab->width && tab->width > tab->precission && tab->width > ft_strlen(nstr))
    {
        if (tab->precission > ft_strlen(nstr))
            tab->lenght += write(1, "0", 1);
        if (tab->dash)
            write (1, nstr, ft_strlen(nstr));
            filling_width(tab->width - (ft_strlen(nstr) + tab->precission), tab);
    }

}
void    i_dash (t_printf *tab, char *nstr, int number)
{
    int diff;

    diff = 0;
    if (tab->width > ft_strlen(nstr))
    {
        if (tab->width > tab->precission)
        {
            diff = tab->precission - ft_strlen(nstr);
            while (diff-- > 0)
                tab->lenght += write(1, "0", 1);
            write (1, nstr, ft_strlen(nstr));
            filling_width(tab->width - (ft_strlen(nstr) + tab->precission), tab);
        }
    }
    else if (tab->width <= ft_strlen(nstr))
}

void    i_conversor(t_printf *tab)
{
    char    *nstr;
    int     n;

    n = va_arg(tab->args, int);
    if (n < 0)
    {
        n = -n;
        tab->sign = 1;
    }
    if (n == 0 && tab->precission == 0 && tab->width == 1)
        write (1,"", 1);
    nstr = ft_itoa(n);

    free (nstr);
}
