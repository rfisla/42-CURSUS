/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_lists_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:28:02 by rufernan          #+#    #+#             */
/*   Updated: 2021/10/26 16:28:03 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sixtiles	*q_values(t_stack **stack_a, t_sixtiles *s, int size)
{
	s->s1n = sixtile_finder(stack_a, size, 1);
	s->s2n = sixtile_finder(stack_a, size, 2);
	s->s3n = sixtile_finder(stack_a, size, 3);
	s->s4n = sixtile_finder(stack_a, size, 4);
	s->s5n = sixtile_finder(stack_a, size, 5);
	s->s1size = size / 6;
	s->s2size = sixtile_size(stack_a, s->s1n, s->s2n, 2);
	s->s3size = sixtile_size(stack_a, s->s2n, s->s3n, 3);
	s->s4size = sixtile_size(stack_a, s->s3n, s->s4n, 4);
	s->s5size = sixtile_size(stack_a, s->s4n, s->s5n, 5);
	s->s6size = sixtile_size(stack_a, s->s5n, 0, 6);
	return (s);
}

static void	push(t_stack **stack_a, t_stack **stack_b, t_sixtiles *s, int sixt)
{
	if (sixt == 1 && ((*stack_a)->number <= s->s1n))
		push_b(stack_a, stack_b);
	else if (sixt == 2 && ((*stack_a)->number > s->s1n && \
			(*stack_a)->number <= s->s2n))
		push_b(stack_a, stack_b);
	else if (sixt == 3 && ((*stack_a)->number > s->s2n && \
			(*stack_a)->number <= s->s3n))
		push_b(stack_a, stack_b);
	else if (sixt == 4 && ((*stack_a)->number > s->s3n && \
			(*stack_a)->number <= s->s4n))
		push_b(stack_a, stack_b);
	else if (sixt == 5 && ((*stack_a)->number > s->s4n && \
			(*stack_a)->number <= s->s5n))
		push_b(stack_a, stack_b);
	else if (sixt == 6 && ((*stack_a)->number > s->s5n))
		push_b(stack_a, stack_b);
	else
		rotate_a(stack_a);
}

static void	push_last(t_stack **s_a, t_stack **s_b, t_sixtiles *sx, int s)
{
	push(s_a, s_b, sx, s);
	check_last(s_a);
}

void	big_lists_sorter(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_sixtiles	*sixtiles;

	sixtiles = (t_sixtiles *) malloc(sizeof(t_sixtiles));
	q_values(stack_a, sixtiles, size);
	while (stack_size(stack_b) < sixtiles->s6size)
		push(stack_a, stack_b, sixtiles, 6);
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < sixtiles->s5size)
		push(stack_a, stack_b, sixtiles, 5);
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < sixtiles->s4size)
		push(stack_a, stack_b, sixtiles, 4);
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < sixtiles->s3size)
		push(stack_a, stack_b, sixtiles, 3);
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < sixtiles->s2size)
		push(stack_a, stack_b, sixtiles, 2);
	sort_quarter(stack_a, stack_b);
	while (stack_size(stack_b) < sixtiles->s1size)
		push_last(stack_a, stack_b, sixtiles, 1);
	sort_last_quarter(stack_a, stack_b);
	free(sixtiles);
}
