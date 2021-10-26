/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sixtiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:52 by rufernan          #+#    #+#             */
/*   Updated: 2021/10/26 16:27:53 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_array(t_stack *stack, int size)
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

int	sixtile_finder(t_stack **stack, int size, int sixtile)
{
	int	*array;
	int	position;

	position = 0;
	array = sort_array(stack, size);
	if (sixtile == 1)
		position = array[size / 6 - 1];
	else if (sixtile == 2)
		position = array[((size / 6) * 2) - 1];
	else if (sixtile == 3)
		position = array[(size / 2) - 1];
	else if (sixtile == 4)
		position = array[((size / 6) * 4) - 1];
	else if (sixtile == 5)
		position = array[((size / 6) * 5) - 1];
	free(array);
	return (position);
}

int	sixtile_size(t_stack **stack, int init, int finish, char sixtile)
{
	int		s_size;
	t_stack	*tmp;

	tmp = *stack;
	s_size = 0;
	if (sixtile != 6)
	{
		while (tmp)
		{
			if (tmp->number > init && tmp->number <= finish)
				s_size++;
			tmp = tmp->next;
		}
	}
	if (sixtile == 6)
	{
		while (tmp)
		{
			if (tmp->number > init)
				s_size++;
			tmp = tmp->next;
		}
	}
	return (s_size);
}
