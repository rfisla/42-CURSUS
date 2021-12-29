#include "minishell.h"

int	check_cd(char *input, char **command)
{
	if (ft_strncmp(command[0], "cd", 2) == 0)
	{
		if (chdir(command[1]) < 0)
			perror(command[1]);
		free(input);
		free_arr(command);
		return(1);
	}
	return(0);
}