/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:59:03 by yorlians          #+#    #+#             */
/*   Updated: 2023/02/25 17:21:49 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len_for_uitoa(unsigned int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*uitoa(unsigned int n)
{
	int		length;
	char	*str;

	length = get_len_for_uitoa(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (str);
	str[length] = '\0';
	while (length != 0)
	{
		str[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (str);
}

int	print_unsigned_int(unsigned int n)
{
	unsigned int	length;
	char			*number;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		number = uitoa(n);
		length = print_string(number);
		free(number);
	}
	return (length);
}
