/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:11:38 by rufernan          #+#    #+#             */
/*   Updated: 2021/08/31 17:11:41 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../LIBFT/libft.h"

void				pipex(char **argv, char **envp);
char				**split_cmd(char *argv);
void				parsing_path(char *cmd, char **envp, char **path);
int					check_args(int argc);
void				free_arr(char **arr);
int					command_exists(char *path, char **cmd);

#endif