/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:27:51 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:24:40 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	~~swap 2 first elements at top of stack A~~
	swap the positions of the first 2 elements
		in stack_a. update data accordingly,
		if specified, print the operation.
*/
void	swap_a(t_stack **stack_a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_size(*stack_a) > 1)
	{
		first = *stack_a;
		second = (*stack_a)-> next;
		first -> next = second -> next;
		second -> next = first;
		*stack_a = second;
		if (print == 1)
			ft_printf("sa\n");
	}
	return ;
}

/*
	~~swap 2 first elements at top of stack B~~
	swap the positions of the first 2 elements
		in stack_b. update data accordingly,
		if specified, print the operation.
*/
void	swap_b(t_stack **stack_b, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_size(*stack_b) > 1)
	{
		first = *stack_b;
		second = (*stack_b)-> next;
		first -> next = second -> next;
		second -> next = first;
		*stack_b = second;
		if (print == 1)
			ft_printf("sb\n");
	}
	return ;
}

/*
				~~swap_a and swap_b at the same time~~
		perform	simultaneous swap of the first two elements 
		in both stack_a and stack_b if they	have more than 1
		element. update data accordingly, if specified, print 
							the operation.
*/
void	swap_both(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (stack_size(*stack_a) > 1)
		swap_a(stack_a, 0);
	if (stack_size(*stack_b) > 1)
		swap_b(stack_b, 0);
	if (print == 1)
		ft_printf("ss\n");
	return ;
}
