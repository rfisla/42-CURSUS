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

#include "../includes/ft_printf.h"

// tratar los int maximos para width y precission
void	width_highest_value_dash(t_printf *tab, char *number)
{
	int	diff;

	diff = tab->precission - ft_strlen(number);
	if (tab->width && tab->width >= tab->precission && \
		tab->width > ft_strlen(number) && tab->dash)
	{
		printing_sign(tab);
		while (diff-- > 0)
			tab->lenght += write(1, "0", 1);
		tab->lenght += write (1, number, ft_strlen(number));
		if (tab->precission > ft_strlen(number))
			filling_width(tab->width - tab->precission, tab);
		else
			filling_width(tab->width - ft_strlen(number), tab);
	}
}

void	width_highest_value_notdash(t_printf *tab, char *number)
{
	int	diff;

	diff = tab->precission - ft_strlen(number);
	if (tab->width && tab->width >= tab->precission && \
		tab->width > ft_strlen(number) && !tab->dash)
	{
		if (tab->zero)
        {
            printing_sign(tab);
            filling_width(tab->width - tab->precission - ft_strlen(number), tab);
        }
        else if (diff > 0)
        {
			filling_width(tab->width - tab->precission, tab);
            printing_sign(tab);
        }
		else
        {
			filling_width(tab->width - ft_strlen(number), tab);
            printing_sign(tab);
        }	
		while (diff-- > 0)
			tab->lenght += write(1, "0", 1);
		tab->lenght += write (1, number, ft_strlen(number));
	}
}

void	precission_highest_value(t_printf *tab, char *number)
{
	int	diff;

	diff = tab->precission - ft_strlen(number);
	if (tab->precission > tab->width && tab->precission > ft_strlen (number))
	{
		printing_sign(tab);
		while (diff-- > 0)
			tab->lenght += write(1, "0", 1);
		tab->lenght += write (1, number, ft_strlen(number));
	}
}

void	len_highest_value(t_printf *tab, char *number)
{
	if ((tab->precission || tab->width) && ft_strlen(number) >= tab->precission \
		&& ft_strlen(number) >= tab->width)
	{
		printing_sign(tab);
		tab->lenght += write(1, number, ft_strlen(number));
	}
}

void	id_conversor(t_printf *tab)
{
	char	*nstr;
	long	n;

	n = va_arg(tab->args, int);
	print_space(tab, n);
	if (n < 0)
	{
		exception_negatives(tab, n);
		n = -n;
	}
	if ((tab->point && tab->zero) || (tab->zero && tab->dash))
		tab->zero = 0;
	nstr = ft_itoa(n);
	if (n == 0 && tab->precission == 0 && tab->width == 0 && tab->point)
		write(1, "", 1);
	else if (!tab->precission && !tab->width)
	{
		printing_sign(tab);
		tab->lenght += write(1, nstr, ft_strlen(nstr));
	}
	precission_highest_value(tab, nstr);
	width_highest_value_dash (tab, nstr);
	width_highest_value_notdash(tab, nstr);
	len_highest_value (tab, nstr);
	free (nstr);
}
