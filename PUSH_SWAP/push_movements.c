#include "push_swap.h"
/*
static void del_first_node(t_stack *stack)
{
	t_stack *aux;

	aux = &stack[0];
	//stack = (*stack)->next;
	free(aux);
}
*/
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *to_a;
	t_stack	*from_b;
	t_stack	*tmp;

	to_a = *stack_a;
	from_b = *stack_b;
	if (!from_b)
		return ;
	tmp = from_b;
	from_b = from_b->next;
	*stack_b = from_b;
	if (!to_a)
	{
		to_a = tmp;
		to_a->next = NULL;
		*stack_a = to_a;
	}
	else
	{
		tmp->next = to_a;
		*stack_a = tmp;
	}

}	
void	push_b(t_stack **stack_a, t_stack **stack_b)
{

	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	to = *stack_b;
	from = *stack_a;
	if (!from)
		return ;
	tmp = from;
	from = from->next;
	*stack_a = from;	
	if (!to)
    {
		to = tmp;
		to->next = NULL;
		*stack_b = to;
    }
	else
	{
		tmp->next = to;
		*stack_b = tmp;
	}
}

