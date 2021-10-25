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

static void	check_head(t_stack **stack)
{
	if ((*stack)->next)
	{
		if ((*stack)->number < (*stack)->next->number)
			swap_b(stack);
	}
}

static int	second_min_best_position(t_stack *f, t_stack *s, t_sixtiles *sixt)
{
	if ((s->index < sixt->s1size || s->index > sixt->s3size) \
		&& (f->index >= sixt->s1size && f->index <= sixt->s3size))
		return (1);
	return (0);
}

static void	to_top(t_stack **stack_a, t_stack **stack_b, int i, t_sixtiles *s)
{
	if (i <= s->s2size)
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
	else if (i > s->s2size)
	{
		while (i < stack_size(stack_a))
		{
			reverse_rotate(stack_a, 'a');
			i++;
		}
	}
	push_b(stack_a, stack_b);
}

static t_sixtiles	*median_values(t_stack **stack_a, t_sixtiles *q, int size)
{
	q->s1n = sixtile_finder(stack_a, size, 1);
	q->s2n = sixtile_finder(stack_a, size, 2);
	q->s3n = sixtile_finder(stack_a, size, 3);
	q->s1size = size / 4;
	q->s2size = sixtile_size(stack_a, q->s1n, q->s2n, 2);
	q->s3size = sixtile_size(stack_a, q->s2n, q->s3n, 3);
	q->s4size = sixtile_size(stack_a, q->s3n, 0, 4);
	return (q);
}

void	under100_lists_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*first;
	t_stack		*second;
	t_sixtiles	*sixtiles;

	sixtiles = (t_sixtiles *) malloc(sizeof(t_sixtiles));
	while (stack_size(stack_a))
	{
		median_values(stack_a, sixtiles, stack_size(stack_a));
		assign_index(stack_a);
		first = hold_first(stack_a);
		second = hold_second(stack_a, first);
		if (second_min_best_position(first, second, sixtiles) \
		&& stack_size(stack_a) >= 20)
			to_top(stack_a, stack_b, second->index, sixtiles);
		else
			to_top(stack_a, stack_b, first->index, sixtiles);
		check_head(stack_b);
	}
	free (sixtiles);
	while (*stack_b)
	{
		if (stack_size(stack_b) == 2)
			check_head(stack_b);
		push_a(stack_a, stack_b);
	}
}
