/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:27:57 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:21:55 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	~~put 1rst element at top of stack A in the bottom of A~~
	perform a rotation on stack_a by moving the top element
	to the bottom. update data accordingly, if specified,
					print the operation.
*/
void	rotate_a(t_stack **stack_a, int print)
{
	t_stack	*start;
	t_stack	*end;

	if (stack_size(*stack_a) > 1)
	{
		start = *stack_a;
		end = stack_last(start);
		*stack_a = start -> next;
		start -> next = NULL;
		end -> next = start;
		if (print == 1)
			ft_printf("ra\n");
	}
	return ;
}

/*
	~~put 1rst element at top of stack B in the bottom of B~~
	perform a rotation on stack_b by moving the top element
	to the bottom. update data accordingly, if specified,
					print the operation.
*/
void	rotate_b(t_stack **stack_b, int print)
{
	t_stack	*start;
	t_stack	*end;

	if (stack_size(*stack_b) > 1)
	{
		start = *stack_b;
		end = stack_last(start);
		*stack_b = start -> next;
		start -> next = NULL;
		end -> next = start;
		if (print == 1)
			ft_printf("rb\n");
	}
	return ;
}

/*
			~~rotate_a and rotate_b at the same time~~
	perform a rotation on both stack_a and stack_b if they
	have more than 1 element. update data accordingly, if
				specified, print the operation.
*/
void	rotate_both(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (stack_size(*stack_a) > 1)
		rotate_a(stack_a, 0);
	if (stack_size(*stack_b) > 1)
		rotate_b(stack_b, 0);
	if (print == 1)
		ft_printf("rr\n");
	return ;
}
