/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:45:08 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 08:24:23 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	initialize stacks, parse comman-line arguments, check if the stack is already 
	sorted, find the median, keep only 3 numbers in stack, sort them if necessary,
	move element to the original stack, rotate the stack to bring the smallest
					number to the top, free and exit.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_median;
	int		i;
	int		median;

	stack_a = NULL;
	stack_b = NULL;
	stack_median = NULL;
	i = 1;
	if (argc < 2 || !argv[1])
		return (0);
	parsing(argv, &stack_a, &stack_median);
	if (sorted_check(&stack_a))
		free_all(&stack_a, &stack_median, NULL, EXIT_SUCCESS);
	median = find_median(&stack_median, &stack_b);
	keep_3_numbers(&stack_a, &stack_b, median);
	if (stack_size(stack_a) > 2)
		sort_3_num(&stack_a);
	while (stack_b)
		put_all_back(&stack_a, &stack_b);
	rotate_in_position(&stack_a);
	free_all(&stack_a, &stack_median, NULL, EXIT_SUCCESS);
}

/*
	check if the stack size is greater than 3, if so, move
	elements from stack_a to stack_b until there are only 3 left.
	if a number in stack_b is less or equal to the median, it
	does a rotation on stack_b to bring the number closer to the top
*/
void	keep_3_numbers(t_stack **stack_a, t_stack **stack_b, int median)
{
	if (*stack_a && stack_size(*stack_a) > 3)
	{
		while (stack_size(*stack_a) > 3)
		{
			push_b(stack_a, stack_b, 1);
			if ((*stack_b)-> number <= median)
				rotate_b(stack_b, 1);
		}
	}
}

/*
	find the index the minimum value in stack_a. compare this index
	with the difference between the stack size and the index. if the 
	index is <, it rotates stack_a until the minimum value is on the top.
	if the difference is smaller it performs a reverse rot on stack_a
				until the minimum value is on the top.
*/
void	rotate_in_position(t_stack **stack_a)
{
	int	min_index;

	min_index = find_index_of_min(*stack_a);
	if (min_index < stack_size(*stack_a) - min_index)
	{
		while (*stack_a && (*stack_a)-> number != find_min(*stack_a))
			rotate_a(stack_a, 1);
	}
	else
	{
		while (*stack_a && (*stack_a)-> number != find_min(*stack_a))
			rev_rot_a(stack_a, 1);
	}
}
