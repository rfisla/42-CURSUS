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

static char	*x_itoa_base(unsigned int nb, unsigned int base, int i)
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

static void	hash_options(t_printf *tab, char *str)
{
	if (tab->hash)
	{
		px_width_highest_dash (tab, str);
		px_width_highest_notdash(tab, str);
	}
	else if (!tab->hash)
	{
		width_highest_value_dash (tab, str);
		width_highest_value_notdash(tab, str, ft_strlen(str));
	}
}

static void	updating_table(t_printf *tab, int choice)
{
	int	i;

	i = choice;
	tab->plus = 0;
	if ((tab->point && tab->zero) || (tab->zero && tab->dash))
		tab->zero = 0;
	if (i == 1 && tab-> hash)
		tab->ox = 2;
}

static void	zero_value_update(t_printf *tab)
{
	tab->hash = 0;
	tab->ox = 0;
}

void	x_conversor(t_printf *tab, int choice)
{
	unsigned int	x;
	char			*str;

	x = va_arg(tab->args, unsigned int);
	str = NULL;
	if (x == 0 && tab->point)
		str = ft_strdup("");
	else if (choice == 0)
		str = x_itoa_base(x, 16, 0);
	else if (choice == 1)
		str = x_itoa_base(x, 16, 1);
	updating_table(tab, choice);
	if (x == 0)
		zero_value_update(tab);
	if (!tab->precission && !tab->width)
	{
		printing_sign(tab);
		tab->lenght += write(1, str, ft_strlen(str));
	}
	precission_highest_value(tab, str);
	len_highest_value (tab, str);
	hash_options(tab, str);
	free(str);
}
