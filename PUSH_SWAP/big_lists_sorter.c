#include "push_swap.h"

void	check_head_b(t_stack **stack)
{
	if ((*stack)->next)
	{
		if ((*stack)->number > (*stack)->next->number)
			swap_b(stack);
	}
}

static int	second_min_best_located(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	int		quarter;

	quarter = stack_size(stack_a) / 4;
	assign_index(stack_a);
	first = hold_first(stack_a);
	second = hold_second(stack_a, first);
	if ((second->index < quarter || second->index > (quarter * 3)) \
		&& (first->index >= quarter && first->index <= (quarter * 3)))
		return (1);
	return (0);
}

void	move_to_first(t_stack **stack_b, int index)
{
	if (index <= (stack_size(stack_b) / 2))
	{
		while (index > 0)
		{
			rotate_a(stack_b);
			index--;
		}
	}
	else if (index > (stack_size(stack_b) / 2))
	{
		while (index < stack_size(stack_b))
		{
			reverse_rotate_a(stack_b, 'b');
			index++;
		}
	}
}

static void	sort_quarter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	while (stack_size(stack_b))
	{
		assign_index(stack_b);
		first = hold_first(stack_b);
		second = hold_second(stack_b, first);
		if (second_min_best_located(stack_b))
		{
			move_to_first(stack_b, second->index);
			assign_index(stack_b);
		}
		move_to_first(stack_b, first->index);
		check_head_b(stack_b);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
}

void	big_lists_sorter(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	quartile_first;
	int	median;
	int	quartile_third;
	int size1;
	int size2;
	int size3;
	int size4;

	size = stack_size(stack_a);
	quartile_first = quartile_finder(stack_a, size, 1);
	median = quartile_finder(stack_a, size, 2);
	quartile_third = quartile_finder(stack_a, size, 3);
	size1 = quartile_size(stack_a, size, 1);
	size2 = quartile_size(stack_a, size, 2);
	size3 = quartile_size(stack_a, size, 3);
	size4 = quartile_size(stack_a, size, 4);
	while (stack_size(stack_b) < size3)
	{
		if ((*stack_a)->number > median && \
			(*stack_a)->number <= quartile_third)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < size2)
	{
		if ((*stack_a)->number > quartile_first && \
			(*stack_a)->number <= median)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < size1)
	{
		if ((*stack_a)->number <= quartile_first)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < size4)
	{
		if ((*stack_a)->number > quartile_third)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_quarter(stack_a, stack_b);
	//printf("\n%d 1QUARTILE:", size / 4);
	//printf("\n%d 2NDQUARTILE:", quartile_size(stack_a, quartile_first, median, 2));
	//printf("\n%d 3NDQUARTILE:", quartile_size(stack_a, median, quartile_third, 3));
	//printf("\n%d 4NDQUARTILE:", quartile_size(stack_a, quartile_third, size, 4));
}
