/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:12:50 by rufernan          #+#    #+#             */
/*   Updated: 2021/07/13 17:12:53 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "LIBFT/libft.h"
# include <stdio.h>
# include <stdarg.h>
# define SPECIFIERS "cspdiuxX%"

typedef struct s_printf
{
    va_list     args;
    int         width;
    int         precission;
    int         lenght;
    int         hash;
    int         zero;
    int         dash;
    int         space;
    int         plus;
    int         point;
}           t_printf;

int     ft_printf (const char *, ...);
int     format_checker(t_printf *tab, const char *format, int i);
int     conversor_checker (t_printf *tab, const char *format, int i);


void    filling_width (int amount, t_printf *tab);
void	ft_print_char(t_printf *tab, int i);



#endif
