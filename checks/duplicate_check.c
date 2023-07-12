/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:23:14 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:07:09 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	check for duplicates of a target in the stack.
	return -1 if duplicate is found, otherwise return 0.
*/
int	duplicate_check(t_stack *stack, int target)
{
	while (stack)
	{
		if (stack -> number == target)
			return (ft_putstr_fd("Error\n", STDERR_FILENO), -1);
		stack = stack -> next;
	}
	return (0);
}
