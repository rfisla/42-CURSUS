#include "push_swap.h"

int	already_sorted(t_stack **stack_a)
{
	t_stack	*stack;

	stack = *stack_a;
	while (stack->next)
	{
		if (!(stack->number < stack->next->number))
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

void	assign_index(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

int	stack_size(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	error_message(t_stack **stack_a)
{
	free_stack(stack_a);
	ft_putendl_fd("error", 2);
	exit (0);
}

void	check_head_b(t_stack **stack)
{
	if ((*stack)->next)
	{
		if ((*stack)->number > (*stack)->next->number)
			swap_b(stack);
	}
}
