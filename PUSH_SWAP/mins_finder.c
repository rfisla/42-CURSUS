/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mins_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:30 by rufernan          #+#    #+#             */
/*   Updated: 2021/10/26 16:27:31 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		sixtile;

	sixtile = stack_size(stack) / 6;
	assign_index(stack);
	first = hold_first(stack);
	second = hold_second(stack, first);
	if ((second->index < (sixtile * 2) || second->index > (sixtile * 4)) \
		&& (first->index >= (sixtile * 2) && first->index <= (sixtile * 4)))
		return (1);
	return (0);
}
