/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:54:53 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 08:10:25 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	perform a specific number of double rotations on both stacks, helping to
				rearrange the elements in a desired manner. 
*/
void	do_double_rot(t_stack **stack_a, t_stack **stack_b, int *ra, int *rb)
{
	int	rotations_a;
	int	rotations_b;

	rotations_a = *ra;
	rotations_b = *rb;
	while (rotations_a > 0 && rotations_b > 0)
	{
		if (rotations_a && rotations_b)
		{
			rotate_both(stack_a, stack_b, 1);
			rotations_a--;
			rotations_b--;
		}
	}
	while (rotations_a < 0 && rotations_b < 0)
	{
		if (rotations_a && rotations_b)
		{
			rev_rot_both(stack_a, stack_b, 1);
			rotations_a++;
			rotations_b++;
		}
	}
	*ra = rotations_a;
	*rb = rotations_b;
}

/*
	perform single rotation on both stacks based on given number of rotations,
			helping to rearrange the elements in a desired manner. 
*/
void	do_single_rot(t_stack **stack_a, t_stack **stack_b, int ra, int rb)
{
	while (ra || rb)
	{	
		if (ra > 0)
		{
			rotate_a(stack_a, 1);
			ra--;
		}
		else if (ra < 0)
		{
			rev_rot_a(stack_a, 1);
			ra++;
		}
		if (rb > 0)
		{
			rotate_b(stack_b, 1);
			rb--;
		}
		else if (rb < 0)
		{
			rev_rot_b(stack_b, 1);
			rb++;
		}
	}
}

/*
	perform rotations on both stacks without printing any output. it
	takes the number of rotations as input and executes the rotations 
								accordingly.
*/
void	rot_no_print(t_stack **stack_a, t_stack **stack_b, int ra, int rb)
{
	while (ra || rb)
	{	
		if (ra > 0)
		{
			rotate_a(stack_a, 0);
			ra--;
		}
		if (rb > 0)
		{
			rotate_b(stack_b, 0);
			rb--;
		}
	}
}

/*
	save the number of rotations for further analysis and 
	decision-making based on the total number of moves 
						required.
*/
int	save_moves(t_ab *rotations, int new_ra, int new_rb)
{
	int	moves;

	moves = 0;
	rotations -> a = new_ra;
	rotations -> b = new_rb;
	if (new_ra < 0)
		new_ra *= -1;
	if (new_rb < 0)
		new_rb *= -1;
	moves = new_ra + new_rb;
	return (moves);
}

/*
	find optimal (min) moves to transfer elements from stack_b to
	stack_a in order to achieve a desired sorting order.
*/
t_ab	find_moves(t_stack	*stack_a, t_stack *stack_b, t_ab size)
{
	t_ab	temp_rot;
	t_ab	rot;
	int		moves;

	temp_rot.b = 0;
	moves = -1;
	while (stack_b)
	{
		temp_rot.a = find_rotations_a(stack_a, stack_b);
		if (temp_rot.a + temp_rot.b < moves || moves == -1)
			moves = save_moves(&rot, temp_rot.a, temp_rot.b);
		if (size.a - temp_rot.a + temp_rot.b < moves)
			moves = save_moves(&rot, temp_rot.a - size.a, temp_rot.b);
		if (temp_rot.a + size.b - temp_rot.b < moves)
			moves = save_moves(&rot, temp_rot.a, temp_rot.b - size.b);
		if ((size.a - temp_rot.a) + (size.b - temp_rot.b) < moves)
			moves = save_moves(&rot, temp_rot.a - size.a, temp_rot.b - size.b);
		temp_rot.b++;
		stack_b = stack_b -> next;
	}
	return (rot);
}
