/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:47:40 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 05:54:39 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
	execute commands provided as strings. takes current state of
	2 stacks and command string as input. purpose of this function 
	is to perform corresponding stack operations based on the 
	command string.
*/
int	do_command(t_stack **stack_a, t_stack **stack_b, char *string)
{
	if (ft_strncmp("sa\n", string, 3) == 0)
		swap_a(stack_a, 0);
	else if (ft_strncmp("sb\n", string, 3) == 0)
		swap_b(stack_b, 0);
	else if (ft_strncmp("ss\n", string, 3) == 0)
		swap_both(stack_a, stack_b, 0);
	else if (ft_strncmp("pa\n", string, 3) == 0)
		push_a(stack_a, stack_b, 0);
	else if (ft_strncmp("pb\n", string, 3) == 0)
		push_b(stack_a, stack_b, 0);
	else if (ft_strncmp("ra\n", string, 3) == 0)
		rotate_a(stack_a, 0);
	else if (ft_strncmp("rb\n", string, 3) == 0)
		rotate_b(stack_b, 0);
	else if (ft_strncmp("rr\n", string, 3) == 0)
		rotate_both(stack_a, stack_b, 0);
	else if (ft_strncmp("rra\n", string, 4) == 0)
		rev_rot_a(stack_a, 0);
	else if (ft_strncmp("rrb\n", string, 4) == 0)
		rev_rot_b(stack_b, 0);
	else if (ft_strncmp("rrr\n", string, 4) == 0)
		rev_rot_both(stack_a, stack_b, 0);
	else
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 0);
	return (1);
}

/*
	main function sets up the stacks, processes
	command-line args, reads commands from standart input,
	executes the commands, checks the state of the stack,
	then frees allocated memory.
*/
int	main(int argc, char **argv)
{
	char	*line;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc < 2 || !argv[1])
		return (0);
	parsing(argv, &stack_a, NULL);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (do_command(&stack_a, &stack_b, line) == 0)
			free_checker(stack_a, stack_b, line, NULL);
		free(line);
	}
	if (stack_a && sorted_check(&stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&stack_a, &stack_b, NULL, EXIT_SUCCESS);
}
