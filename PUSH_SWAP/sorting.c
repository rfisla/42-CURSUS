#include "push_swap.h"

static void	sort_two(t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		swap_a(stack);
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

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{

	//t_stack	*tmp;

	//tmp = *stack_a;
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a,stack_b);
	sort_three(stack_a);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	if ((*stack_a)->number > (*stack_b)->number)
		push_a(stack_a, stack_b);
	else if ((*stack_a)->number < (*stack_b)->number)
	{
		push_a(stack_a, stack_b);
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}

}
/*
static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a,stack_b);
	if ((*stack_a)->number > (*stack_a)->next->next->next->number)
		rotate_a(stack_a);
	else
		sort_three(stack_a);

	push_a(stack_a, stack_b); //	PPROBLEMA CON ESTE PUSH?????
	//if ((*stack_a)->number > (*stack_a)->next->next->next->next->number)
		//rotate_a(stack_a);
	if ((*stack_a)->number > (*stack_a)->next->next->next->number)
		rotate_a(stack_a);
	else if ((*stack_a)->number > (*stack_a)->next->number)
	{
		swap_a(stack_a);
		sort_three(stack_a);
	}
	//printf("\n\n%d\n\n", last->number);
}
*/
void	short_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (already_sorted(stack_a))
		return ;
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}


