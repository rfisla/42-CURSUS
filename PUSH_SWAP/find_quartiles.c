#include "push_swap.h"

static int	*get_array(t_stack *stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	tmp = stack;
	i = 0;
	array = malloc(sizeof(int) * (size + 1));
	if (!(array))
		return (0);
	while (tmp)
	{
		array[i++] = tmp->number;
		tmp = tmp->next;
	}
	return (array);
}

int	*sort_array(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		temp;
	int		i;

	tmp = *stack;
	array = get_array(tmp, size);
	i = 0;
	while (size > 1)
	{
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
			i++;
		}
		size--;
		i = 0;
	}
	return (array);
}

int	quartile_finder(t_stack **stack, int size, int quartile)
{
	int	*array;
	int	position;

	array = sort_array(stack, size);
	if (quartile == 1)
		position = array[size / 4 - 1];
	else if (quartile == 2)
		position = array[size / 2 - 1];
	else if (quartile == 3)
		position = array[(size / 4)*3 - 1];
	return (position);
}


/*
int	quartile_size(t_stack **stack, int init, int finish, char quartile)
{
	int	q_size;
	t_stack *tmp;

	tmp = *stack;
	q_size = 0;
	if (quartile != 4)
	{
		while (tmp)
		{
			if (tmp->number > init && tmp->number <= finish)
				q_size++;
			tmp = tmp->next;
		}
	}
	if (quartile == 4)
	{
		while (tmp)
		{
			if (tmp->number > init)
				q_size++;
			tmp = tmp->next;
		}
	}
	free_stack(&tmp);
	return (q_size);
}

ESTO FUNCIONA
*/
int	quartile_size(t_stack **stack, int size, int quartile)
{
	int	q_size;
	t_stack *tmp;
	int	quartile_first;
	int	median;
	int	quartile_third;

	quartile_first = quartile_finder(stack, size, 1);
	median = quartile_finder(stack, size, 2);
	quartile_third = quartile_finder(stack, size, 3);

	tmp = *stack;
	q_size = 0;
	if (quartile == 1)
	{
		while (tmp)
		{
			if (tmp->number <= quartile_first)
				q_size++;
			tmp = tmp->next;
		}
	}
	if (quartile == 2)
	{
		while (tmp)
		{
			if (tmp->number > quartile_first && tmp->number <= median)
				q_size++;
			tmp = tmp->next;
		}
	}
	if (quartile == 3)
	{
		while (tmp)
		{
			if (tmp->number > median && tmp->number <= quartile_third)
				q_size++;
			tmp = tmp->next;
		}
	}
	if (quartile == 4)
	{
		while (tmp)
		{
			if (tmp->number > quartile_third)
				q_size++;
			tmp = tmp->next;
		}
	}
	free_stack(&tmp);
	return (q_size);
}

