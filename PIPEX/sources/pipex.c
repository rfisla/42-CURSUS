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

static void	child_process(int *end, char **argv, char **envp)
{
	int		fd;
	char	**cmd;
	char	*path;

	close(end[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit (0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	cmd = split_cmd(argv[2]);
	parsing_path(cmd[0], envp, &path);
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("Command not found", 2);
		free_arr(cmd);
		free(path);
		exit (0);
	}
}

static void	parent_process(int *end, char **argv, char **envp)
{
	int		fd;
	//int		child_status;
	char	**cmd;
	char	*path;

	close(end[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND | S_IRWXU);
	if (fd < 0)
		exit(0);
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	dup2(fd, STDOUT_FILENO);
	//close(fd);
	cmd = split_cmd(argv[3]);
	parsing_path(cmd[0], envp, &path);
	if (execve(path, cmd, envp) == 1)
	{
		ft_putstr_fd("Command not found", 2);
		free_arr(cmd);
		free(path);
		exit (0);
	}
}

/*one end will write and the other will read.From now on we will say that end[1]
is the child process, and end[0] the parent process, and that the child writes,
while theparent reads. so cmd1 will be executed by the child,and cmd2 by the parent*/

void	pipex(char **argv, char **envp)
{
	int		end[2];
	pid_t	subprocess;

	pipe(end);
	subprocess = fork();
	if (subprocess < 0)
		perror("Fork: ");
	if (!subprocess)
		child_process(end, argv, envp);
	else
	{
		subprocess = fork();
		if (subprocess < 0)
			perror("Fork: ");
		if (!subprocess)
			parent_process(end, argv, envp);
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
