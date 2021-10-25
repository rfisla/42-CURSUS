#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*iterator;
	t_stack	*last_item;

	tmp = *stack_a;
	if (!(tmp && tmp->next))
		return ;
	last_item = tmp;
	*stack_a = tmp->next;
	iterator = *stack_a;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = last_item;
	iterator->next->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*iterator;
	t_stack	*last_item;

	tmp = *stack_b;
	if (!(tmp && tmp->next))
		return ;
	last_item = tmp;
	*stack_b = tmp->next;
	iterator = *stack_b;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = last_item;
	iterator->next->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	reverse_rotate(t_stack **stack, char letter)
{
	t_stack	*last;
	t_stack	*r_stack;
	t_stack	*previous;

	r_stack = *stack;
	if (!(r_stack && r_stack->next))
		return ;
	last = r_stack;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = r_stack;
	*stack = last;
	if (letter == 'a')
		ft_putendl_fd("rra", 1);
	else if (letter == 'b')
		ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 'a');
	reverse_rotate(stack_b, 'b');
	ft_putendl_fd("rrr", 1);
}
