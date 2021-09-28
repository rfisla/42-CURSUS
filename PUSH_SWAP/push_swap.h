/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:33:21 by rufernan          #+#    #+#             */
/*   Updated: 2021/09/02 19:33:24 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SIZE
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "LIBFT/libft.h"

typedef	struct s_stack
{
    int		size;
	int		number;
	struct	s_stack *next;
}	t_stack;

t_stack	*create_new_node(void);

t_stack	*init_stack_a(int size);
void    free_array(char **items);
void    free_stack(t_stack **stack);
t_stack	*get_stack(int size, char **args);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_a_b(t_stack **stack_a, t_stack **stack_b);

void push_b(t_stack **stack_a, t_stack **stack_b);
void push_a(t_stack **stack_a, t_stack **stack_b);







#endif
