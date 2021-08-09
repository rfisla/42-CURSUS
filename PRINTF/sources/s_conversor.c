/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:56:51 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/04 15:56:54 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	common_exception(t_printf *tab)
{
	if (tab->width)
		filling_width(tab->width, tab);
	else
		write(1, "", 1);
}

void	notdash_width_precission(t_printf *tab, char *str)
{
	if (tab->point && !tab->precission)
		common_exception(tab);
	else if (tab->width > ft_strlen(str))
	{
		if (tab->precission && tab->precission <= ft_strlen(str))
		{
			filling_width(tab->width - tab->precission, tab);
			tab->lenght += write(1, str, tab->precission);
		}
		else
		{
			filling_width(tab->width - ft_strlen(str), tab);
			tab->lenght += write(1, str, ft_strlen(str));
		}
	}
	else if ((!tab->width || tab->width <= ft_strlen(str)) && \
			tab->precission > ft_strlen(str))
		tab->lenght += write(1, str, ft_strlen(str));
	else if ((!tab->width || tab->width <= ft_strlen(str)) && \
			tab->precission && tab->precission <= ft_strlen(str))
		tab->lenght += write(1, str, tab->precission);
}

void	dash_width_precission(t_printf *tab, char *str)
{
	if (tab->point && !tab->precission)
		common_exception(tab);
	else if (tab->width > ft_strlen(str))
	{
		if (tab->precission && tab->precission <= ft_strlen(str))
		{
			tab->lenght += write(1, str, tab->precission);
			filling_width(tab->width - tab->precission, tab);
		}
		else
		{
			tab->lenght += write(1, str, ft_strlen(str));
			filling_width(tab->width - ft_strlen(str), tab);
		}
	}
	else if ((!tab->width || tab->width <= ft_strlen(str)) && \
			tab->precission > ft_strlen(str))
		tab->lenght += write(1, str, ft_strlen(str));
	else if ((!tab->width || tab->width <= ft_strlen(str)) && \
			tab->precission && tab->precission <= ft_strlen(str))
		tab->lenght += write(1, str, tab->precission);
	else if ((!tab->width || tab->width <= ft_strlen(str)) && \
            ((tab->point && tab->precission) || tab->precission <= ft_strlen(str)))
        tab->lenght += write(1, str, ft_strlen(str));;
}

void	s_conversor(t_printf *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (!str)
		write (1, "", 1);
	if (tab->plus)
		tab->plus = 0;
	if (tab->zero && tab->dash)
		tab->zero = 0;
	if ((!tab->width && !tab->precission) && !tab->point)
		tab->lenght += write(1, str, ft_strlen(str));
	else if (!tab->dash)
		notdash_width_precission(tab, str);
	else
		dash_width_precission(tab, str);
}
