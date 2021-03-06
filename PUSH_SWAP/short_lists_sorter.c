/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_lists_sorter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:53 by rufernan          #+#    #+#             */
/*   Updated: 2021/10/26 16:26:54 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		reverse_rotate(stack_a, 'a');
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
		reverse_rotate(stack_a, 'a');
}

static t_stack	*find_min(t_stack **stack)
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
	return (hold_first);
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		bingo;
	t_stack	*min;

	bingo = 0;
	min = find_min(stack_a);
	while (!bingo)
	{
		if ((*stack_a)->number == min->number)
		{
			push_b(stack_a, stack_b);
			bingo++;
		}
		else if ((*stack_a)->next->number == min->number)
		{	
			swap_a(stack_a);
			push_b(stack_a, stack_b);
			bingo++;
		}
		else
			rotate_a(stack_a);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		bingo;
	t_stack	*min;

	bingo = 0;
	while (bingo < 2)
	{
		min = find_min(stack_a);
		if ((*stack_a)->number == min->number)
		{
			push_b(stack_a, stack_b);
			bingo++;
		}
		else if ((*stack_a)->next->number == min->number)
		{	
			swap_a(stack_a);
			push_b(stack_a, stack_b);
			bingo++;
		}
		else
			rotate_a(stack_a);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	short_list_sorter(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			swap_a(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
