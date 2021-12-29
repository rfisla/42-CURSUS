#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <unistd.h>
# include <sys/wait.h>
# include "LIBFT/libft.h"

void	free_arr(char **arr);
int		check_cd(char *input, char **command);


#endif