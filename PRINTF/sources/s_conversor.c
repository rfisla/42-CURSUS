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

static void	common_exception(t_printf *tab)
{
	if (tab->width)
		filling_width(tab->width, tab);
}

static void	notdash_width_precission(t_printf *tab, char *str)
{
	int	diff;

	diff = tab->precission - ft_strlen(str);
	if (tab->point && !tab->precission)
		common_exception(tab);
	else if (tab->width > ft_strlen(str))
	{
		if (tab->precission && diff <= 0)
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
	else if ((!tab->width || tab->width <= ft_strlen(str)) && diff > 0)
		tab->lenght += write(1, str, ft_strlen(str));
	else if ((!tab->width || tab->width <= ft_strlen(str)) && \
			tab->precission && diff <= 0)
		tab->lenght += write(1, str, tab->precission);
}

static void	dash_width_precission(t_printf *tab, char *str)
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
			((tab->point && tab->precission) || tab->precission <= \
			ft_strlen(str)))
		tab->lenght += write(1, str, ft_strlen(str));
}

static void	updating_table(t_printf *tab)
{
	if (tab->plus)
		tab->plus = 0;
	if (tab->zero && tab->dash)
		tab->zero = 0;
}

void	s_conversor(t_printf *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	updating_table(tab);
	if (!str || (!tab->precission && !tab->width && tab->point))
	{
		str = ft_strdup("");
		free(str);
	}
	else if ((!tab->width && !tab->precission) && !tab->point)
		tab->lenght += write(1, str, ft_strlen(str));
	else if (!tab->dash)
		notdash_width_precission(tab, str);
	else
		dash_width_precission(tab, str);
}
