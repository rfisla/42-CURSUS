/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:57:42 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/04 15:57:44 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	uint_len(unsigned int number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		++len;
		number = number / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	int		len;
	char	*str;

	len = uint_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (n == 0)
		str[0] = '0';
	while (i < len)
	{
		str[len - i - 1] = (n % 10) + '0';
		n = n / 10;
		++i;
	}
	return (str);
}

void	u_conversor(t_printf *tab)
{
	unsigned int	u;
	char			*str;

	u = va_arg(tab->args, unsigned int);
	print_space(tab, u);
	if ((tab->point && tab->zero) || (tab->zero && tab->dash))
		tab->zero = 0;
	tab->plus = 0;
	str = ft_uitoa(u);
	if (u == 0 && tab->precission == 0 && tab->width == 0 && tab->point)
		write(1, "", 1);
	else if (!tab->precission && !tab->width)
		tab->lenght += write(1, str, ft_strlen(str));
	precission_highest_value(tab, str);
	width_highest_value_dash (tab, str);
	width_highest_value_notdash(tab, str);
	len_highest_value (tab, str);
	free (str);
}
