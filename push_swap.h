/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:45:21 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 08:35:52 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "utils/Libft/libft.h"
# include "utils/ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ab
{
	int		a;
	int		b;
}	t_ab;

/*
	~INSTRUCTIONS~
*/
//push.c (a, b)
void	push_a(t_stack **stack_a, t_stack **stack_b, int print);
void	push_b(t_stack **stack_a, t_stack **stack_b, int print);

//swap.c (a, b, both)
void	swap_a(t_stack **stack_a, int print);
void	swap_b(t_stack **stack_b, int print);
void	swap_both(t_stack **stack_a, t_stack **stack_b, int print);

//rotate.c (a, b, both)
void	rotate_a(t_stack **stack_a, int print);
void	rotate_b(t_stack **stack_b, int print);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, int print);

//reverse_rotate.c (a, b, both)
void	rev_rot_a(t_stack **stack_a, int print);
void	rev_rot_b(t_stack **stack_b, int print);
void	rev_rot_both(t_stack **stack_a, t_stack **stack_b, int print);

/*
	~CHECKS~
*/
//integer_check.c
int		integer_check(char *string);
int		check_max_min_int(char *string);
//parcing.c
void	parsing(char **argv, t_stack **stack_a, t_stack **stack_median);
//duplicate_check.c
int		duplicate_check(t_stack *stack, int target);
//sorted_check.c
int		sorted_check(t_stack **stack);

/*
	~SORT~
*/
void	sort_3_num(t_stack **stack);

/*
	~UTILS~
*/
//list_utils.c
int		stack_size(t_stack *lst);
void	stack_add_back(t_stack **lst, t_stack *new);
void	stack_add_front(t_stack **lst, t_stack *new);
t_stack	*stack_new(int content);
t_stack	*stack_last(t_stack *lst);

//find_min_max.c
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_index_of_min(t_stack *stack);
int		find_median(t_stack **stack_median, t_stack **stack_b);

//free_all.c
void	free_stack(t_stack *stack);
void	free_all(t_stack **stack1, t_stack **stack2, char **array, int ex_code);
void	free_array(char **p);
void	free_checker(t_stack *stack1, t_stack *stack2, char *str, char **array);

//index_a.c
int		find_rotations_a(t_stack *stack_a, t_stack *stack_b);

//moves.c
void	do_double_rot(t_stack **stack_a, t_stack **stack_b, int *ra, int *rb);
void	do_single_rot(t_stack **stack_a, t_stack **stack_b, int ra, int rb);
int		save_moves(t_ab *rotations, int new_ra, int new_rb);
t_ab	find_moves(t_stack	*stack_a, t_stack *stack_b, t_ab size);
void	rot_no_print(t_stack **stack_a, t_stack **stack_b, int ra, int rb);

//push_back_a.c
void	put_all_back(t_stack **stack_a, t_stack **stack_b);
void	put_all_back_median(t_stack **stack_a, t_stack **stack_b);

//push_swap.c
void	keep_3_numbers(t_stack **stack_a, t_stack **stack_b, int median);
void	rotate_in_position(t_stack **stack_a);

#endif