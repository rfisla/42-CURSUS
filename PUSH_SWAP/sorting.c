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
	ft_putendl_fd("Stack already sorted", 0);
	return (1);
}

static void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		swap_a(stack_a);
}

static void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->next->\
	next->number && (*stack_a)->next->next->number > (*stack_a)->number)
		swap_a(stack_a);
	else if ((*stack_a)->number > (*stack_a)->next->number && \
		(*stack_a)->next->number > (*stack_a)->next->next->number && \
		(*stack_a)->next->next->number < (*stack_a)->number)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a, 'a');
	}
	else if ((*stack_a)->number > (*stack_a)->next->number && \
		(*stack_a)->next->number < (*stack_a)->next->next->number && \
		(*stack_a)->next->next->number < (*stack_a)->number)
		rotate_a(stack_a);
	else if ((*stack_a)->number < (*stack_a)->next->number && \
		(*stack_a)->next->number > (*stack_a)->next->next->number && \
		(*stack_a)->next->next->number > (*stack_a)->number)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_a)->number < (*stack_a)->next->number && \
		(*stack_a)->next->number > (*stack_a)->next->next->number && \
		(*stack_a)->next->next->number < (*stack_a)->number)
		reverse_rotate_a(stack_a, 'a');
}

void	short_sort(t_stack **stack_a, int size)
{
	if (already_sorted(stack_a))
		return ;
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
}
