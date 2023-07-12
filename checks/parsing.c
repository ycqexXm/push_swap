/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:26:08 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 05:21:34 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	iterate trough each command-line argument, starting from index 1
	(skip program name). take command-line args, split them into individual args,
	check their validity, detect duplicates, create stack_nodes and add them to 
	stack_a and stack_median. if one of the checks is failed, free allocated
	memory and exit with failure status.
*/
void	parsing(char **argv, t_stack **stack_a, t_stack **stack_median)
{
	int		i;
	int		j;
	char	**arguments;

	i = 0;
	while (argv[++i])
	{
		arguments = ft_split(argv[i], ' ');
		if (!(*arguments))
			ft_putstr_fd("Error\n", STDERR_FILENO);
		if (!(*arguments))
			free_all(stack_a, stack_median, arguments, EXIT_FAILURE);
		j = -1;
		while (arguments[++j])
		{
			if (integer_check(arguments[j]) == -1)
				free_all(stack_a, stack_median, arguments, EXIT_FAILURE);
			if (duplicate_check(*stack_a, ft_atoi(arguments[j])))
				free_all(stack_a, stack_median, arguments, EXIT_FAILURE);
			stack_add_back(stack_a, stack_new(ft_atoi(arguments[j])));
			if (stack_median)
				stack_add_back(stack_median, stack_new(ft_atoi(arguments[j])));
		}
		free_array(arguments);
	}
}
