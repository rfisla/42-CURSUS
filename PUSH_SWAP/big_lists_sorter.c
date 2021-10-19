#include "push_swap.h"

static void	move_to_first(t_stack **stack, int index)
{
	if (index <= (stack_size(stack) / 2))
	{
		while (index > 0)
		{
			rotate_a(stack);
			index--;
		}
	}
	else if (index > (stack_size(stack) / 2))
	{
		while (index < stack_size(stack))
		{
			reverse_rotate_a(stack, 'b');
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

static t_quartiles	*q_values(t_stack **stack_a, t_quartiles *q, int size)
{
	q->q1n = quartile_finder(stack_a, size, 1);
	q->q2n = quartile_finder(stack_a, size, 2);
	q->q3n = quartile_finder(stack_a, size, 3);
	q->q1size = size / 4;
	q->q2size = quartile_size(stack_a, q->q1n, q->q2n, 2);
	q->q3size = quartile_size(stack_a, q->q2n, q->q3n, 3);
	q->q4size = quartile_size(stack_a, q->q3n, 0, 4);
	return (q);
}

static void	push_q(t_stack **stack_a, t_stack **stack_b, t_quartiles *qr, int q)
{
	if (q == 1 && ((*stack_a)->number <= qr->q1n))
		push_b(stack_a, stack_b);
	else if (q == 2 && ((*stack_a)->number > qr->q1n && \
			(*stack_a)->number <= qr->q2n))
		push_b(stack_a, stack_b);
	else if (q == 3 && ((*stack_a)->number > qr->q2n && \
			(*stack_a)->number <= qr->q3n))
		push_b(stack_a, stack_b);
	else if (q == 4 && ((*stack_a)->number > qr->q3n))
		push_b(stack_a, stack_b);
	else
		rotate_a(stack_a);
}

void	big_lists_sorter(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_quartiles	*quartiles;

	quartiles = (t_quartiles *) malloc(sizeof(t_quartiles));
	q_values(stack_a, quartiles, size);
	while (stack_size(stack_b) < quartiles->q3size)
		push_q(stack_a, stack_b, quartiles, 3);
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < quartiles->q2size)
		push_q(stack_a, stack_b, quartiles, 2);
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < quartiles->q1size)
		push_q(stack_a, stack_b, quartiles, 1);
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < quartiles->q4size)
		push_q(stack_a, stack_b, quartiles, 4);
	sort_quarter(stack_a, stack_b);
}
