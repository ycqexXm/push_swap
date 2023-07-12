/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:32:02 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:29:17 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	sort 3 numbers in ascending order. check if stack is already sorted
	if so, return without making any changes. find maximum number, then
	do rotate_a if max number is on top, rev_rot_a if max number is in the 
	middle, swap_a if top number is greater than the second number. 
*/
void	sort_3_num(t_stack **stack)
{
	int	max;

	if (sorted_check(stack))
		return ;
	max = find_max(*stack);
	if ((*stack)-> number == max)
		rotate_a(stack, 1);
	if ((*stack)-> next -> number == max)
		rev_rot_a(stack, 1);
	if ((*stack)-> number > (*stack)-> next -> number)
		swap_a(stack, 1);
}
