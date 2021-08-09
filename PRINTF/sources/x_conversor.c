/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:57:51 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/04 15:57:53 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_conversor(t_printf *tab, int choice)
{
	unsigned int	x;
	char			*str;

	x = va_arg(tab->args, unsigned int);
	if (str == 0 && tab->point)
		str = ft_strdup("");
	else if (choice == 0)
		str = ft_itoa_base(x, 16, 0);
	else if (choice == 1)
		str = ft_itoa_base(x, 16, 1);
	if ((tab->point && tab->zero) || (tab->zero && tab->dash))
		tab->zero = 0;
	if (!tab->precission && !tab->width)
	{
		printing_sign(tab);
		tab->lenght += write(1, str, ft_strlen(str));
	}
	precission_highest_value(tab, str);
	len_highest_value (tab, str);
	if (tab->hash)
	{
		px_width_highest_value_dash (tab, str);
		px_width_highest_value_notdash(tab, str);
	}
	else
	{
		width_highest_value_dash (tab, str);
		width_highest_value_notdash(tab, str);
	}
	free(str);
}
