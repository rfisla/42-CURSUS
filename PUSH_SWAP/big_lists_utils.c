#include "push_swap.h"

void	move_to_first(t_stack **stack_a, t_stack **stack_b, int index)
{
	if (index <= (stack_size(stack_b) / 2))
	{
		while (index > 0)
		{
			rotate_b(stack_b);
			index--;
		}
	}
	else if (index > (stack_size(stack_b) / 2))
	{
		while (index < stack_size(stack_b))
		{
			reverse_rotate(stack_b, 'b');
			index++;
		}
	}
	push_a(stack_a, stack_b);
}

void	check_last(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	if (tmp->number > tmp->next->number)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
		swap_a(stack_a);
	}
}

void	sort_quarter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	while (stack_size(stack_b))
	{
		assign_index(stack_b);
		first = hold_first(stack_b);
		second = hold_second(stack_b, first);
		if (second_max_best_located(stack_b) && stack_size(stack_b) >= 40)
		{
			assign_index(stack_b);
			move_to_first(stack_a, stack_b, second->index);
		}
		else
			move_to_first(stack_a, stack_b, first->index);
	}
}

void	sort_last_quarter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;

	while (stack_size(stack_b))
	{
		assign_index(stack_b);
		first = hold_first(stack_b);
		move_to_first(stack_a, stack_b, first->index);
	}
}
