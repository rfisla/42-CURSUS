/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:13:05 by rufernan          #+#    #+#             */
/*   Updated: 2021/07/13 17:13:09 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf	*ft_init_tab(t_printf *tab)
{
	tab->width = 0;
	tab->precission = 0;
	tab->lenght = 0;
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

static int	conversor_checker(t_printf *tab, const char *format, int i)
{
	if (format[i] == 'c')
		c_conversor(tab, 0);
	else if (format[i] == 's')
		s_conversor(tab);
	else if (format[i] == 'p')
		p_conversor(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		id_conversor(tab);
	else if (format[i] == 'u')
		u_conversor(tab);
	else if (format[i] == 'x')
		x_conversor(tab, 0);
	else if (format[i] == 'X')
		x_conversor(tab, 1);
	else if (format[i] == '%')
		c_conversor(tab, 1);
	return (i);
}

static void	format_options(t_printf *tab, const char *format, int i)
{
	if (format[i] == ' ')
		tab->space = 1;
	else if (format[i] == '-')
		tab->dash = 1;
	else if (format[i] == '0')
		tab->zero = 1;
	else if (format[i] == '.')
		tab->point = 1;
	else if (format[i] == '+')
		tab->plus = 1;
	else if (format[i] == '#')
		tab->hash = 1;
}

static int	format_checker(t_printf *tab, const char *format, int i)
{
	while (!ft_strchr(SPECIFIERS, format[++i]))
	{
		format_options(tab, format, i);
		if (ft_isdigit(format[i]))
		{
			if (tab->point && !tab->precission)
				tab->precission = ft_atoi(&format[i]);
			else if (!tab->width)
				tab->width = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				i++;
			i--;
		}
	}
	conversor_checker(tab, format, i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_printf	*tab;
	int			len;
	int			i;

	i = -1;
	len = 0;
	tab = (t_printf *) malloc(sizeof(t_printf));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i = format_checker(tab, format, i);
			ft_reset_tab(tab);
		}
		else
			len += write(1, &format[i], 1);
	}
	va_end(tab->args);
	len += tab->lenght;
	free(tab);
	return (len);
}
