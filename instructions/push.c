/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:27:55 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:22:08 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
			~~put 1rst from top of B at top of A~~
	move the top element of B to A. update data accordingly,
			if specified, print the operation.
*/
void	push_a(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*from_b;
	t_stack	*to_a;
	t_stack	*temp;

	if (stack_size(*stack_b) > 0)
	{
		to_a = *stack_a;
		from_b = *stack_b;
		temp = from_b;
		from_b = from_b -> next;
		*stack_b = from_b;
		if (!to_a)
		{
			to_a = temp;
			to_a -> next = NULL;
			*stack_a = to_a;
		}
		else
		{
			temp -> next = to_a;
			*stack_a = temp;
		}
		if (print == 1)
			ft_printf("pa\n");
	}
}

/*
			~~put 1rst from top of A at top of B~~
	move the top element of A to B. update data accordingly,
			if specified, print the operation.
*/
void	push_b(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*from_a;
	t_stack	*to_b;
	t_stack	*temp;

	if (stack_size(*stack_a) > 0)
	{
		to_b = *stack_b;
		from_a = *stack_a;
		temp = from_a;
		from_a = from_a -> next;
		*stack_a = from_a;
		if (!to_b)
		{
			to_b = temp;
			to_b -> next = NULL;
			*stack_b = to_b;
		}
		else
		{
			temp -> next = to_b;
			*stack_b = temp;
		}
		if (print == 1)
			ft_printf("pb\n");
	}
}
