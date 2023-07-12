/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:27:47 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:22:03 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
		~~put last element of stack A at top~~
	perform reverse rotation on stack_a by moving the 
	last element on the top. update data accordingly,
			if specified, print the operation.
*/
void	rev_rot_a(t_stack **stack_a, int print)
{
	t_stack	*start;
	t_stack	*end;

	if (stack_size(*stack_a) > 1)
	{
		start = *stack_a;
		end = stack_last(start);
		while (start)
		{
			if (start -> next -> next == NULL)
			{
				start -> next = NULL;
				break ;
			}
			start = start -> next;
		}
		end -> next = *stack_a;
		*stack_a = end;
		if (print == 1)
			ft_printf("rra\n");
	}
	return ;
}

/*
		~~put last element of stack B at top~~
	perform reverse rotation on stack_b by moving the 
	last element on the top. update data accordingly,
			if specified, print the operation.
*/
void	rev_rot_b(t_stack **stack_b, int print)
{
	t_stack	*start;
	t_stack	*end;

	if (stack_size(*stack_b) > 1)
	{
		start = *stack_b;
		end = stack_last(start);
		while (start)
		{
			if (start -> next -> next == NULL)
			{
				start -> next = NULL;
				break ;
			}
			start = start -> next;
		}
		end -> next = *stack_b;
		*stack_b = end;
		if (print == 1)
			ft_printf("rrb\n");
	}
	return ;
}

/*
			~~rev_rot_a and rev_rot_b at same time~~
	perform reverse rotation on both stack_a and stack_b if they
	have more than 1 element. update data accordingly,
			if specified, print the operation.	
*/
void	rev_rot_both(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (stack_size(*stack_a) > 1)
		rev_rot_a(stack_a, 0);
	if (stack_size(*stack_b) > 1)
		rev_rot_b(stack_b, 0);
	if (print == 1)
		ft_printf("rrr\n");
	return ;
}
