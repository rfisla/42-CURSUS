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

static int	second_min_best_position(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	int		quarter;

	if (stack_size(stack_a) >= 20)
	{
		quarter = stack_size(stack_a) / 4;
		assign_index(stack_a);
		first = hold_first(stack_a);
		second = hold_second(stack_a, first);
		if ((second->index < quarter || second->index > (quarter * 3)) \
			&& (first->index >= quarter && first->index <= (quarter * 3)))
			return (1);
	}
	return (0);
}

static void	move_to_top(t_stack **stack_a, t_stack **stack_b, int index)
{
	if (index <= (stack_size(stack_a) / 2))
	{
		while (index > 0)
		{
			rotate_a(stack_a);
			index--;
		}
	}
	else if (index > (stack_size(stack_a) / 2))
	{
		while (index < stack_size(stack_a))
		{
			reverse_rotate_a(stack_a, 'a');
			index++;
		}
	}
	push_b(stack_a, stack_b);
}

void    under100_lists_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	while (stack_size(stack_a))
	{
		assign_index(stack_a);
		first = hold_first(stack_a);
		second = hold_second(stack_a, first);
		if (second_min_best_position(stack_a))
			move_to_top(stack_a, stack_b, second->index);
		else
			move_to_top(stack_a, stack_b, first->index);
		check_head(stack_b);
	}
	while (*stack_b)
	{
		if (stack_size(stack_b) == 2)
			check_head(stack_b);
		push_a(stack_a, stack_b);
	}	
}

