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
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "LIBFT/libft.h"

typedef struct s_stack
{
	int				index;
	int				number;
	struct s_stack	*next;
}					t_stack;

typedef struct s_sixtiles
{
	int		s1size;
	int		s1n;
	int		s2size;
	int		s2n;
	int		s3size;
	int		s3n;	
	int		s4size;
	int		s4n;
	int		s5size;
	int		s5n;
	int		s6size;
}	t_sixtiles;

t_stack		*create_new_node(void);
t_stack		*init_stack_a(int size);
int			int_checker(char *item);
int			duplicates_checker(t_stack **stack, int size);
int			check_int_overflow(char *item);
int			check_len(char *item);
int			get_stack(char **args, t_stack **stack_a, int argc);
void		error_message(t_stack **stack_a);
void		free_array(char **items);
void		free_stack(t_stack **stack);
int			already_sorted(t_stack **stack_a);
int			min_finder(t_stack **stack, int size);
int			*get_array(t_stack *stack, int size);
int			*sort_array(t_stack **stack, int size);
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_a_b(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		reverse_rotate(t_stack **stack, char letter);
void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		short_list_sorter(t_stack **stack_a, t_stack **stack_b, int size);
void		assign_index(t_stack **stack);
int			stack_size(t_stack **stack);
void		check_head_b(t_stack **stack);
t_stack		*hold_first(t_stack **stack);
t_stack		*hold_second(t_stack **stack, t_stack *hold_first);
int			second_min_best_located(t_stack **stack);
int			sixtile_finder(t_stack **stack, int size, int sixtile);
int			sixtile_size(t_stack **stack, int init, int finish, char sixtile);
void		move_to_first(t_stack **stack_a, t_stack **stack_b, int index);
void		check_last(t_stack **stack_a);
void		sort_quarter(t_stack **stack_a, t_stack **stack_b);
void		sort_last_quarter(t_stack **stack_a, t_stack **stack_b);
void		big_lists_sorter(t_stack **stack_a, t_stack **stack_b, int size);
void		under100_lists_sorter(t_stack **stack_a, t_stack **stack_b);

#endif
