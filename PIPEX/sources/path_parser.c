/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:53:05 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/31 19:53:07 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*find_path_word(char **envp)
{
	int	i;

	i = 0;
	while (*envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (0);
}

void	parsing_path(char *cmd, char **envp, char **path)
{
	char	**splitted_path;
	char	*path_no_cmd;
	char	*path_cmd;
	int		i;
	int		fd;

	i = 0;
	splitted_path = ft_split(ft_strchr(find_path_word(envp), '/'), ':');
	while (splitted_path[i])
	{
		path_no_cmd = ft_strjoin(splitted_path[i], "/");
		path_cmd = ft_strjoin(path_no_cmd, cmd);
		fd = open(path_cmd, O_RDONLY);
		if (fd > 0)
		{
			*path = path_cmd;
			close (fd);
		}
		free(path_no_cmd);
		free (path_cmd);
		free (splitted_path);
		i++;
	}
	free (splitted_path);
}

char	**split_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	return (cmd);
}
