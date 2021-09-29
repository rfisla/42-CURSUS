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
	//tmp = tmp->next;
	//*stack_a = tmp;
	*stack_a = tmp->next; //probar esto en sustitución de las dos líneas anteriores
	iterator = *stack_a;
	while(iterator->next)
		iterator = iterator->next;
	iterator->next = create_new_node();
	iterator->next = last_item;
	iterator->next->next = NULL;
	ft_putendl_fd("ra", 0);
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
	//tmp = tmp->next;
	//*stack_a = tmp;
	*stack_b = tmp->next; //probar esto en sustitución de las dos líneas anteriores
	iterator = *stack_b;
	while(iterator->next)
		iterator = iterator->next;
	iterator->next = create_new_node();
	iterator->next = last_item;
	iterator->next->next = NULL;
	ft_putendl_fd("rb", 0);
}

void	reverse_rotate_a(t_stack **stack_a, char stack)
{
	t_stack	*last;
	t_stack *r_stack;
	t_stack	*previous;

	r_stack = *stack_a;
	if (!(r_stack && r_stack->next))
		return;
	last = r_stack;
	while(last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = r_stack;
	*stack_a = last;
	if (stack == 'a')
		ft_putendl_fd("rra", 0);
}

void	reverse_rotate_b(t_stack **stack_b, char stack)
{
	t_stack	*last;
	t_stack *r_stack;
	t_stack	*previous;

	r_stack = *stack_b;
	if (!(r_stack && r_stack->next))
		return;
	last = r_stack;
	while(last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = r_stack;
	*stack_b = last;
	if (stack == 'b')
		ft_putendl_fd("rrb", 0);
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a, '-');
	reverse_rotate_b(stack_b, '-');
	ft_putendl_fd("rrr", 0);
}
