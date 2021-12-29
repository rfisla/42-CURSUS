#include "minishell.h"


static char	**get_input(char *input)
{
	char	**command;
	char	**parsed;
	int		i;

	command = (char**)malloc (sizeof(char *) * 8);
	i = 0;
	if(!command)
	{
		perror("malloc failed");
		exit(1);
	}
	parsed = ft_split(input, ' ');
	while(parsed[i])
	{
		command[i] = parsed[i];
		i++;
	}
	command[i] = NULL;
	free(parsed);
	return(command);
}


void	fork_process(char **command, char *input, pid_t child, int *status)
{
		if (child < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (child == 0)
		{
			if (execvp(command[0], command) == -1)
			{
					perror("Incorrect choice");
					free(input);
					free_arr(command);
					exit(1);//it terminates the child process
			}
		}
		else
			waitpid(child, status, WUNTRACED);
}

int main (void)
{
	char	*input;
	char	**command;
	pid_t	child_process;
	int		status;

	while(1)
	{
		//This is the parent process
		input = readline("Minishell> ");
		command = get_input(input);
		if (!command[0])
		{
			free(input);
			free_arr(command);
			continue;
		}
		else if (check_cd(input, command))
			continue;
		child_process = fork();
		fork_process(command, input, child_process, &status);
	}
	free(input);
	free(command);
	return (0);
}