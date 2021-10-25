#include "push_swap.h"

int	int_checker(char *item)
{
	int	i;

	i = 0;
	if (item[i] == '-')
		i++;
	while (item[i])
	{
		if ((!ft_isdigit(item[i])))
			return (0);
		i++;
	}
	if ((i > 1 && !ft_isdigit(item[1])) || (i == 1 && !ft_isdigit(item[0])))
		return (0);
	return (1);
}

int	duplicates_checker(int n, t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	tmp = *stack;
	array = get_array(tmp, size);
	i = 0;
	while (array[i])
	{
		if (array[i] == n)
			return (1);
		i++;
	}
	free(array);
	return (0);
}

int	check_int_overflow(char *item)
{
	if (item[0] == '-')
	{
		if (ft_atoi(item) > 0)
			return (1);
	}
	if (item[0] != '-')
	{
		if (ft_atoi(item) < 0)
			return (1);
	}
	return (0);
}

int	check_len(char *item)
{
	int		i;

	i = 0;
	while (item[i])
		i++;
	if (i > 11)
		return (1);
	return (0);
}

int	check_zeros(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->number == 0)
			i++;
		tmp = tmp->next;
	}
	if (i > 1)
		return (1);
	return (0);
}
