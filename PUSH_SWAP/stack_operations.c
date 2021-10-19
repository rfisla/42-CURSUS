#include "push_swap.h"

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->number = 0;
	first->next = NULL;
	first->index = 1;
	return (first);
}

static int	int_checker(char *item)
{
	int	i;

	i = 0;
	if (item[i] == '-')
		i++;
	while (item[i])
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

void	get_stack(int size, char **args, t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;
	int		status;
	int		n;

	i = 1;
	status = 0;
	*stack_a = create_new_node();
	tmp = *stack_a;
	while (i < size && !status)
	{
		n = ft_atoi(args[i]);
		if (!(int_checker(args[i])) || !(duplicates_checker(n, stack_a)) \
		|| n > INT_MAX || n < INT_MIN)
			status = 1;
		tmp->number = ft_atoi(args[i]);
		if (i < size - 1)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		i++;
	}
	if (status)
		error_message(stack_a);
}
