/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:11:56 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 08:13:44 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	move all elements from stack_b to stack_a in an optimal way.
*/
void	put_all_back(t_stack **stack_a, t_stack **stack_b)
{
	int		moves;
	t_ab	rot;
	t_ab	size;
	t_stack	*temp_b;

	moves = -1;
	rot.a = 0;
	rot.b = 0;
	size.a = stack_size(*stack_a);
	size.b = stack_size(*stack_b);
	temp_b = *stack_b;
	rot = find_moves(*stack_a, temp_b, size);
	do_double_rot(stack_a, stack_b, &rot.a, &rot.b);
	do_single_rot(stack_a, stack_b, rot.a, rot.b);
	push_a(stack_a, stack_b, 1);
}

/*
	rearrange the elements and return them to stack_a while
	maintaining a specific order, such as median value being 
							at the top.
*/
void	put_all_back_median(t_stack **stack_a, t_stack **stack_b)
{
	int		moves;
	t_ab	rotations;
	t_ab	temp_rotations;
	t_stack	*temp_b;

	moves = -1;
	rotations.a = 0;
	rotations.b = 0;
	temp_rotations.b = 0;
	temp_b = *stack_b;
	temp_b = *stack_b;
	while (temp_b)
	{
		temp_rotations.a = find_rotations_a(*stack_a, temp_b);
		if (temp_rotations.a + temp_rotations.b < moves || moves == -1)
			moves = save_moves(&rotations, temp_rotations.a, temp_rotations.b);
		temp_rotations.b++;
		temp_b = temp_b -> next;
	}
	rot_no_print(stack_a, stack_b, rotations.a, rotations.b);
	push_a(stack_a, stack_b, 0);
}
