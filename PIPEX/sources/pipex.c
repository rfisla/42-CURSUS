/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:11:14 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/31 17:11:16 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	first_process(int *end, char **argv, char **envp)
{
	int		fd;
	char	**cmd;
	char	*path;

	close(end[0]);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	fd = open(argv[1], O_RDONLY);
	file1_checker(argv, fd);
	dup2(fd, STDIN_FILENO);
	cmd = split_cmd(argv[2]);
	parsing_path(cmd[0], envp, &path);
	command_exists(path, cmd);
	if (execve(path, cmd, envp) == -1)
	{
		free_arr(cmd);
		free(path);
		exit (0);
	}
}

static void	second_process(int *end, char **argv, char **envp)
{
	int		fd;
	char	**cmd;
	char	*path;

	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	file2_checker(argv, fd);
	dup2(fd, STDOUT_FILENO);
	cmd = split_cmd(argv[3]);
	parsing_path(cmd[0], envp, &path);
	command_exists(path, cmd);
	if (execve(path, cmd, envp) == -1)
	{
		free_arr(cmd);
		free(path);
		exit (0);
	}
}

void	pipex(char **argv, char **envp)
{
	int		end[2];
	pid_t	subprocess;

	pipe(end);
	subprocess = fork();
	if (subprocess < 0)
		perror("Fork: ");
	if (!subprocess)
		first_process(end, argv, envp);
	else
	{
		subprocess = fork();
		if (subprocess < 0)
			perror("Fork: ");
		if (!subprocess)
			second_process(end, argv, envp);
		else
		{
			close(end[0]);
			close(end[1]);
		}	
	}
	waitpid(subprocess, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	check_args(argc);
	pipex (argv, envp);
	return (0);
}
