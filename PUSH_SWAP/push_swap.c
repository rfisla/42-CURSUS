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

	if ((argc - 1) < 1)
		exit (0);
	size = get_stack(argv, &stack_a, argc);
	if (duplicates_checker(&stack_a, size))
		error_message(&stack_a);
	stack_b = NULL;
	if (already_sorted(&stack_a))
		return (0);
	else if (size <= 5)
		short_list_sorter(&stack_a, &stack_b, size);
	else if (size > 5 && size < 100)
		under100_lists_sorter(&stack_a, &stack_b);
	else if (size >= 100)
		big_lists_sorter(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
