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

static int	searching_min(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	tmp = *stack;
	i = 0;
	array = malloc(sizeof(int) * (size + 1));
	if (!(array))
		return (0);
	while (tmp)
	{
		array[i++] = tmp->number;
		tmp = tmp->next;
	}
	i = 1;
	while (array[i])
	{
		if (array[0] > array[i])
		{
			free(array);
			return (0);
		}
		i++;
	}
	free(array);
	return (1);
}

int	min_finder(t_stack **stack, int size)
{
	if (searching_min(stack, size) == 1)
		return (1);
	return (0);
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


t_stack	*hold_first(t_stack **stack)
{
	t_stack	*hold_first;
	t_stack	*tmp;

	tmp = *stack;
	hold_first = *stack;
	while (tmp->next)
	{
		if (tmp->next->number < hold_first->number)
		{
			hold_first = tmp->next;
			hold_first->index = tmp->next->index;
		}
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->number == hold_first->number)
			hold_first->index = tmp->index;
		tmp = tmp->next;
	}
	return (hold_first);
}

t_stack	*hold_second(t_stack **stack, t_stack *hold_first)
{
	t_stack	*tmp;
	t_stack	*hold_second;

	tmp = *stack;
	hold_second = *stack;
	while (tmp->next)
	{
		if (tmp->next->number < hold_second->number && tmp->next->number != hold_first->number)
			hold_second = tmp->next;
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->number == hold_second->number)
			hold_second->index = tmp->index;
		tmp = tmp->next;
	}
	return (hold_second);
}
