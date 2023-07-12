/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:31 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:49:52 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	free memory for dynamically allocated
	array of strings. free individual strings,
			free the array itself.
*/
void	free_array(char **p)
{
	unsigned int	i;

	i = 0;
	while (p != NULL && p[i] != NULL)
	{
		free(p[i]);
		i++;
	}
	if (p != NULL)
		free(p);
}

/*
	free memory allocated for linked list
	of t_stack nodes. free each node, starting
				from head.
*/
void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack -> next;
		free(temp);
	}
}

/*
	free memory allocated for the checker.
*/
void	free_checker(t_stack *stack1, t_stack *stack2, char *str, char **array)
{
	if (stack1 != NULL)
		free_stack(stack1);
	if (stack2 != NULL)
		free_stack(stack2);
	if (str != NULL)
		free(str);
	if (array != NULL)
		free_array(array);
	exit(EXIT_FAILURE);
}

/*
		free memory allocated for various components used in push_swap.
*/
void	free_all(t_stack **stack1, t_stack **stack2, char **array, int ex_code)
{
	if (stack1 != NULL && *stack1 != NULL)
		free_stack(*stack1);
	if (stack2 != NULL && *stack2 != NULL)
		free_stack(*stack2);
	if (array != NULL)
		free_array(array);
	exit(ex_code);
}
