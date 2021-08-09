/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:57:03 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/04 15:57:05 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_numlen_base(unsigned long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		i += 1;
		return (i);
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long nb, unsigned int base, int i)
{
	char	*ret;
	char	*numbers;
	int		size;

	if (i == 0)
		numbers = ft_strdup("0123456789abcdef");
	else
		numbers = ft_strdup("0123456789ABCDEF");
	ret = NULL;
	size = ft_numlen_base(nb, base);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	ret[size--] = '\0';
	while (size >= 0)
	{
		ret[size--] = numbers[nb % base];
		nb /= base;
	}
	free(numbers);
	return (ret);
}
/*
void	ft_putnbr_base(unsigned long number)
{
	int		len;

	len = 16;
	if (number < 0)
	{
		number = -number;
		ft_putchar('-');
	}
	if (number > len)
	{
		ft_putnbr_base((number / len));
		ft_putnbr_base((number % len));
	}
	else
		ft_putchar_fd('0' + number, 1);
}

*/

void	px_width_highest_value_dash(t_printf *tab, char *number)
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
			filling_width(tab->width - tab->precission - 2, tab);
		else
			filling_width(tab->width - ft_strlen(number) - 2, tab);
	}
}

void	px_width_highest_value_notdash(t_printf *tab, char *number)
{
	int	diff;

	diff = tab->precission - ft_strlen(number);
	if (tab->width && tab->width >= tab->precission && \
		tab->width > ft_strlen(number) && !tab->dash)
	{
		if (diff > 0)
			filling_width(tab->width - tab->precission - 2, tab);
		else
			filling_width(tab->width - ft_strlen(number) - 2, tab);
		printing_sign(tab);
		while (diff-- > 0)
			tab->lenght += write(1, "0", 1);
		tab->lenght += write (1, number, ft_strlen(number));
	}
}

void	p_conversor(t_printf *tab)
{
	unsigned long	pointer;
	char			*str;

	pointer = (unsigned long) va_arg(tab->args, void *);
	tab->ox = 1;
	if (pointer == 0 && tab->point)
		str = ft_strdup("");
	else
		str = ft_itoa_base(pointer, 16, 0);
	//str = ft_strjoin("10", str);
	if ((tab->point && tab->zero) || (tab->zero && tab->dash))
		tab->zero = 0;
	if (!tab->precission && !tab->width)
	{
		printing_sign(tab);
		tab->lenght += write(1, str, ft_strlen(str));
	}
	precission_highest_value(tab, str);
	px_width_highest_value_dash (tab, str);
	px_width_highest_value_notdash(tab, str);
	len_highest_value (tab, str);
	free(str);
}
