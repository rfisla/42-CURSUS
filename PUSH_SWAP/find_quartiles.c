#include "push_swap.h"

static int	*get_array(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	tmp = *stack;
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
	int		*array;
	int		temp;
	int		i;

	array = get_array(stack, size);
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

int	first_quartile(t_stack **stack, int size)
{
	int	*array;
	int	first_quartile;

	array = sort_array(stack, size);
	first_quartile = array[size / 4 - 1];
	return (first_quartile);
}

int	median(t_stack **stack, int size)
{
	int	*array;
	int	median;

	array = sort_array(stack, size);
	median = array[size / 2 - 1];
	return (median);
}

int	third_quartile(t_stack **stack, int size)
{
	int	*array;
	int	third_quartile;

	array = sort_array(stack, size);
	third_quartile = array[(size / 4)*3 - 1];
	return (third_quartile);
}
