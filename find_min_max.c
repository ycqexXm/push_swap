/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:52:54 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 08:09:12 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	find the minimum value in a linked list.
*/
int	find_min(t_stack *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack -> number < min)
			min = stack -> number;
		stack = stack -> next;
	}
	return (min);
}

/*
	find the maximum value in a linked list.
*/
int	find_max(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack -> number > max)
			max = stack -> number;
		stack = stack -> next;
	}
	return (max);
}

/*
	find index position of the minimum value in a
					linked list.
*/
int	find_index_of_min(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

	min = INT_MAX;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack -> number < min)
		{
			pos = i;
			min = stack -> number;
		}
		i++;
		stack = stack -> next;
	}
	return (pos);
}

/*
	find median value in a stack. move elements to another stack
	until only 2 elements remain, restore them back, find the smallest
	element, locate the median based on the desired size. return the 
					value of median element.
*/
int	find_median(t_stack **stack_median, t_stack **stack_b)
{
	int		size;
	t_stack	*temp;

	size = stack_size(*stack_median) / 2;
	if (*stack_median && stack_size(*stack_median) > 2)
	{
		while (stack_size(*stack_median) > 2)
			push_b(stack_median, stack_b, 0);
	}
	while (*stack_b)
		put_all_back_median(stack_median, stack_b);
	while (*stack_median && (*stack_median)-> number != find_min(*stack_median))
		rotate_a(stack_median, 0);
	temp = *stack_median;
	while (size--)
		temp = temp -> next;
	return (temp -> number);
}
