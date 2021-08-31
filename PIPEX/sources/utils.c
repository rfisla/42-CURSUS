/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:13:48 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/31 19:13:51 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	check_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Incorrect number os arguments", 2);
		exit(0);
	}
	return (0);
}
