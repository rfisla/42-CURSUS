/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_under_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:02:07 by rufernan          #+#    #+#             */
/*   Updated: 2021/10/20 21:02:09 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//OPCIÓN 1
static void	check_head(t_stack **stack)
{
	if ((*stack)->next)
	{
		if ((*stack)->number < (*stack)->next->number)
			swap_b(stack);
	}
}

static int	second_min_best_position(t_stack *f, t_stack *s, t_quartiles *q)
{
	if ((s->index < q->q1size || s->index > q->q3size) \
		&& (f->index >= q->q1size && f->index <= q->q3size))
		return (1);
	return (0);
}

static void	to_top(t_stack **stack_a, t_stack **stack_b, int i, t_quartiles *q)
{
	if (i <= q->q2size)
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
	else if (i > q->q2size)
	{
		while (i < stack_size(stack_a))
		{
			reverse_rotate(stack_a, 'a');
			i++;
		}
	}
	push_b(stack_a, stack_b);
}

static t_quartiles	*median_values(t_stack **stack_a, t_quartiles *q, int size)
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

void	under100_lists_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*first;
	t_stack		*second;
	t_quartiles	*quartiles;

	quartiles = (t_quartiles *) malloc(sizeof(t_quartiles));
	while (stack_size(stack_a))
	{
		median_values(stack_a, quartiles, stack_size(stack_a));
		assign_index(stack_a);
		first = hold_first(stack_a);
		second = hold_second(stack_a, first);
		if (second_min_best_position(first, second, quartiles) \
		&& stack_size(stack_a) >= 20)
			to_top(stack_a, stack_b, second->index, quartiles);
		else
			to_top(stack_a, stack_b, first->index, quartiles);
		check_head(stack_b);
		
	}
	free (quartiles);
	while (*stack_b)
	{
		if (stack_size(stack_b) == 2)
			check_head(stack_b);
		push_a(stack_a, stack_b);
	}
}
