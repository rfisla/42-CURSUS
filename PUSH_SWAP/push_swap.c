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
	else if (size > 5 && size < 100)
		under100_lists_sorter(&stack_a, &stack_b);
	else if (size >= 100)
		big_lists_sorter(&stack_a, &stack_b, size);
	t_stack *tmp = stack_a;
	while(tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->next;
	}
	if (already_sorted(&stack_a))
		printf("SORTED\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
