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


int main(int argc, char **argv)
{ 
    t_stack *stack_a;
    t_stack *stack_b;
    int     size;

	size = argc - 1;
    get_stack(argc, argv, &stack_a);
    stack_b = NULL;


    short_list_sorter(&stack_a, &stack_b, size);
    //printf("%d\n", stack_a->size);
    //swap_a(&stack_a);
    //push_b(&stack_a, &stack_b);
    //push_a(&stack_a, &stack_b);

    //push_b(&stack_a, &stack_b);
    //push_b(&stack_a, &stack_b);
    //push_b(&stack_a, &stack_b);
    //reverse_rotate_both(&stack_a, &stack_b);


    //push_b(&stack_a, &stack_b);
    //printf("%d\n", stack_a->next->number);
    //already_sorted(&stack_a);
    //sort_two(&stack_a, argc - 1);   
    t_stack *puntero;
    puntero = stack_a;
    while (puntero)
    {
        printf("%d\n", puntero->number);
        puntero = puntero -> next;
    }
    /*
    t_stack *puntero2;
    puntero2 = stack_b;
    printf("%s\n\n", "LISTA B");
    while (puntero2)
    {
        printf("%d\n", puntero2->number);
        puntero2 = puntero2 -> next;
    }    
  */
    //system("leaks push_swap");
    return (0);

}
