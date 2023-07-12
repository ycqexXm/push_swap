/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:06:04 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:06:53 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	iterate trough the stack and check if all elements are
	in ascending order. if any element is greater than the
	next after it, return 0, otherwise return 1.
*/
int	sorted_check(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current && current -> next != NULL)
	{
		if (current -> number > current -> next -> number)
			return (0);
		current = current -> next;
	}
	return (1);
}
