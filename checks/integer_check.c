/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:22:36 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:07:04 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	check if the given string contains integers within 
	the range of INT_MIN and INT_MAX. return -1 if
	the string contains an integer outside this range,
	otherwise 0.
*/
int	check_max_min_int(char *string)
{
	int			i;
	long int	result;
	int			sign;

	result = 0;
	i = 0;
	sign = 1;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(string[i]))
	{
		result = result * 10 + (string[i] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

/*
	check if the string contains only digits. check if the numbers
	are pos or neg, if sign found increment i by 1, to skip the sign.
	function iterates trough each char until null terminator. return
	-1 if string is not valid, otherwise return 0.
*/
int	integer_check(char *string)
{
	int	i;
	int	has_digits;

	i = 0;
	has_digits = 0;
	if (*string == '\0')
		return (ft_putstr_fd("Error\n", STDERR_FILENO), -1);
	if (*string == '-' || *string == '+')
		i++;
	while (string[i] != '\0')
	{
		if (string[i] < '0' || string[i] > '9')
			return (ft_putstr_fd("Error\n", STDERR_FILENO), -1);
		has_digits = 1;
		i++;
	}
	if (has_digits == 0)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), -1);
	if (check_max_min_int(string) == -1)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), -1);
	return (0);
}
