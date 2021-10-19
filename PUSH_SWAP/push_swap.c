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
	if (size < 1)
		exit (0);
	get_stack(argc, argv, &stack_a);
	stack_b = NULL;
	if (already_sorted(&stack_a))
		return (0);
	else if (size <= 5)
		short_list_sorter(&stack_a, &stack_b, size);
	//ESTO ES PRUEBA
	//else if (size == 20)
		//array = sort_array(&stack_a, size);
	else if(size > 5)
		big_lists_sorter(&stack_a, &stack_b);
	//else if (size > 100)
		//bigger_list_sorter(&stack_a, &stack_b);
	
	/*
	int i = 0;
	int * array;

	while (array[i])
	{
		printf("%d\n", array[i]);
		i++;
	}
	printf("\n%d\n", first_quartile(&stack_a, size));
	printf("\n%d\n", median(&stack_a, size));
	printf("\n%d\n", third_quartile(&stack_a, size));

*/


	
	t_stack	*list;
	list = stack_a;
	
	
	while (list)
	{
		printf("%d\n", list->number);
		list = list->next;
	}
	
	
	//system("leaks push_swap"); 

	return (0); 

}
