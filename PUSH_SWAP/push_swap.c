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
    //t_stack *stack_b;

	stack_a = get_stack(argc, argv);
    stack_b = NULL;
    //printf("%d\n", stack_a->size);
    //swap_a(&stack_a);
    push_b(&stack_a, &stack_b);
    //push_a(&stack_a, &stack_b);


    //push_b(&stack_a, &stack_b);
    printf("%d\n", stack_a->number);
    /*t_stack *puntero;
    puntero = stack_a;
    while (puntero)
    {
        printf("%d\n", puntero->number);
        puntero = puntero -> next;
    }
    */
  
   
    //printf("\n\n%d\n", stack_b->items[0]);

    //system("leaks push_swap");
    return (0);

}
