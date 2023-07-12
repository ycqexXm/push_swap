/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:47:06 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 05:53:02 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../push_swap.h"
# include "../utils/Get_Next_Line/get_next_line_bonus.h"

int	do_command(t_stack **stack_a, t_stack **stack_b, char *string);

#endif