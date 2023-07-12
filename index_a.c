/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:17:03 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 08:08:59 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	calculate the number of rotations needed to bring specific element from
	stack_b to stack_b to stack_a. by iterating trough stack_a check if the
	current element is greater than the number at the top of stack_b or is
	less than the current next_num. if so update next_num. move to next element.
*/
int	find_rotations_a(t_stack *stack_a, t_stack *stack_b)
{
	int		index;
	int		i;
	int		next_num;
	t_stack	*temp;

	i = 0;
	index = 0;
	next_num = stack_b -> number;
	temp = stack_a;
	while (temp != NULL)
	{
		if (temp -> number > stack_b -> number && \
			(temp -> number < next_num || next_num == stack_b -> number))
		{
			next_num = temp -> number;
			index = i;
		}
		i++;
		temp = temp -> next;
	}
	if (next_num == stack_b -> number || next_num == find_min(stack_a))
		return (find_index_of_min(stack_a));
	return (index);
}
