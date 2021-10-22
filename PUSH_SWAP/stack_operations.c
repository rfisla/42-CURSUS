#include "push_swap.h"

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->number = 0;
	first->next = NULL;
	first->index = 1;
	return (first);
}

static int	int_checker(char *item)
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
	return (1);
}
//PROBLEMA DEL 0 ESTA AQUI. GET ARRAY?
static int	duplicates_checker(int n, t_stack **stack, int size)
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
	return (0);
}

static int		check_int_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}
void	get_stack(int size, char **args, t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;
	int		n;
	int		j;
	char	**array;

	i = 1;
	*stack_a = create_new_node();
	tmp = *stack_a;
	while (i < size)// O mejor args[i]
	{
		array = ft_split(args[i], ' ');
		j = 0;
		while(array[j])
		{
			n = ft_atoi(array[j]);
			if (!(int_checker(array[j])) || (duplicates_checker(n, stack_a, size)) \
			|| check_int_overflow(args[i]))
				error_message(stack_a);
			tmp->number = ft_atoi(array[j]);
			if (i < size - 1)
			{
				tmp->next = create_new_node();
				tmp = tmp->next;
			}
			j++;
		}
		i++;
	}
}
//Trucos para comprobar en 42: el size con $ARG es 2?
//The other option, check both
/*
void	get_stack(int size, char **args, t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;
	int		n;

	i = 1;
	*stack_a = create_new_node();
	tmp = *stack_a;
	while (i < size)
	{
		n = ft_atoi(args[i]);
		if (!(int_checker(args[i])) || (duplicates_checker(n, stack_a, size)) \
		|| check_int_overflow(args[i]))
			error_message(stack_a);
		tmp->number = ft_atoi(args[i]);
		if (i < size - 1)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		i++;
	}
}
*/
//https://github.com/AdrianWR/push_swap/blob/main/src/get_stack.c
/*
static int	duplicates_checker(int n, t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	tmp = *stack;
	array = get_array(tmp, size);
	i = 0;
	zero = 0;
	while (array[i])
	{
		if (array[i] == n)
			return (0);
		i++;
	}
	return (1);
}
*/