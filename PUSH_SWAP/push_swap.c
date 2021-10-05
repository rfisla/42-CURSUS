/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:33:09 by rufernan          #+#    #+#             */
/*   Updated: 2021/09/02 19:33:11 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	size = argc - 1;
	get_stack(argc, argv, &stack_a);
	stack_b = NULL;
	if (already_sorted(&stack_a))
		return (0);
	else if (size <= 5)
		short_list_sorter(&stack_a, &stack_b, size);
	else
		big_lists_sorter(&stack_a, &stack_b);
	/*
	t_stack	*list;
	list = stack_a;
	while (list)
	{
		printf("%d\n", list->number);
		list = list->next;
	}
	*/
	//system("leaks push_swap"); 
	return (0); 
}
