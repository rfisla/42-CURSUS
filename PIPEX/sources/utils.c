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
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		ft_putstr_fd("./pipex archivo1 comando1 comando2 archivo2\n", 2);
		exit(0);
	}
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	//*arr = NULL;
}


//EL problema de los leaks está en esta función
int	path_exists(char *path, char **cmd)
{
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(*cmd, 2);
		exit(0);
	}
	/*else if (access(path, R_OK) == -1)
		ft_putstr_fd("open: read permission denied\n", 2);
	else if (access(path, W_OK) == -1)
		ft_putstr_fd("open: write permission denied\n", 2);
	else
		return (1);*/
	return (0);	
}