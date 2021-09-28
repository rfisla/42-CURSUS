#include "push_swap.h"

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack*)malloc(sizeof(t_stack));
	first->number = 0;
	first->next = NULL;
	first->size = 1;
	return (first);
}

static int	int_checker(char *item)
{
	int	i;

	i = 0;
	if (item[i] == '-')
		i++;
	while(item[i])
	{
		if ((!ft_isdigit(item[i])))
			return (0);
		i++;
	}
	return (1);
}

static int	duplicates_checker(int n, t_stack **stack)
{
	t_stack	*copy;

	copy = *stack;
	while (copy)
	{
		if (copy->number == n)
			return (0);
		copy = copy->next;
	}
	return (1);
}


t_stack	*get_stack(int size, char **args)
{
	t_stack	*stack;
	t_stack *tmp;
	int		i;
	int		status;
	int		n;
	//char	**items;

	if (size < 1)
		exit (0);
	i = 1;
	status = 0;
	stack = create_new_node();
	tmp = stack;
	while (i < size && !status)
	{
		
		n = ft_atoi(args[i]);
		if (!(int_checker(args[i])) || !(duplicates_checker(n, &stack))\
			|| n > INT_MAX || n < INT_MIN)	
			status = 1;
		tmp->number = ft_atoi(args[i]);
		if (i < size - 1)
		{
			tmp->size +=1;
			tmp->next = create_new_node();
			tmp = stack->next;
		}
		i++;
	}
	if (status)
	{
		free_stack(&stack);
		ft_putendl_fd("error", 2);
		exit (0);
	}
	return (stack);
}