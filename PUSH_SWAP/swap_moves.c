#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void	swap_a(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (!(tmp && tmp->next))
		return ;
	else
		ft_swap(&tmp->number, &tmp->next->number);
	ft_putendl_fd("sa", 0);
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	if (!(tmp && tmp->next))
		return ;
	else
		ft_swap(&tmp->number, &tmp->next->number);
	ft_putendl_fd("sb", 0);
}

void	swap_a_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (tmp_a && tmp_a->next)
	{
		ft_swap(&tmp_a->number, &tmp_a->next->number);
	}
	if (tmp_b && tmp_b->next)
	{
		ft_swap(&tmp_b->number, &tmp_b->next->number);
	}
	ft_putendl_fd("ss", 0);
}

