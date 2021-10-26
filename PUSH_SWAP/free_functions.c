/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:43 by rufernan          #+#    #+#             */
/*   Updated: 2021/10/26 16:27:45 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **items)
{
	int	i;

	i = 0;
	while (items[i])
	{
		free(items[i]);
		i++;
	}
	free(items);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*delete;

	tmp = *stack;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->next;
		free(delete);
	}
	*stack = NULL;
}
