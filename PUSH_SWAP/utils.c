#include "push_swap.h"

void    free_array(char **items)
{
    int i;

    i = 0;
    while (items[i])
    {
        free(items[i]);
        i++;
    }
    free(items);
}

void    free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *delete;

    tmp = *stack;
	while(tmp)
    {
        delete = tmp;
        tmp = tmp->next;
        free(delete);
    }
    *stack = NULL;
}


int	already_sorted(t_stack **stack_a)
{
	t_stack	*stack;

	stack = *stack_a;
	while (stack->next)
	{
		if (!(stack->number < stack->next->number))
			return (0);
		else
			stack = stack->next;
	}
	ft_putendl_fd("Stack already sorted", 0);
	return (1);
}

int array_int(t_stack **stack, int size)
{
    t_stack *tmp;
    int *array;
    int i;
    int first;

    tmp = *stack;
    i = 0;
    first = 0;
    array = malloc(sizeof(int) * (size + 1));
    if (!(array))
        return (0);
    while (tmp->next)
    {
        array[i] = tmp->number;
        i++;
        tmp = tmp->next;
    }
    array[i] = tmp->number;
    i = 1;
    while (array[i])
    {
        if (array[first] > array[i])
        {
            free(array);
            return (0);
        }        
        i++;
    }
    free(array);
    return (1);
}
int min_finder(t_stack **stack, int size)
{
    
    if (array_int(stack, size) == 1)
        return (1);
    return (0);
}