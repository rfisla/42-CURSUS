#include "push_swap.h"

static int	searching_min(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	tmp = *stack;
	array = get_array(tmp, size);
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
		if (tmp->next->number < hold_second->number && \
			tmp->next->number != hold_first->number)
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

int	second_min_best_located(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		quarter;

	quarter = stack_size(stack) / 6;
	assign_index(stack);
	first = hold_first(stack);
	second = hold_second(stack, first);
	if ((second->index < quarter || second->index > (quarter * 5)) \
		&& (first->index >= quarter && first->index <= (quarter * 5)))
		return (1);
	return (0);
}
