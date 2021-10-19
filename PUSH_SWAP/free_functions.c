#include "push_swap.h"

void	free_array(char **items)
{
	int	i;

	i = 0;
	while (items[i])
	{
		free(items[i]);
		i++;
	}
	free(items);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*delete;

	tmp = *stack;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->next;
		free(delete);
	}
	*stack = NULL;
}
