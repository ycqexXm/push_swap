/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:58:59 by yorlians          #+#    #+#             */
/*   Updated: 2023/02/25 15:36:35 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len_for_ptr(unsigned long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0 && n > 0)
	{
		n = n / 16;
		length++;
	}
	return (length);
}

char	*ptr_to_str(unsigned long n, char *input)
{
	int		length;
	char	*str;

	length = get_len_for_ptr(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (str);
	str[length] = '\0';
	while (length != 0)
	{
		str[length - 1] = input[n % 16];
		n = n / 16;
		length--;
	}
	return (str);
}

int	print_ptr(unsigned long *n, char *input)
{
	int				length;
	char			*str;
	unsigned long	number;

	number = (unsigned long)n;
	str = ptr_to_str(number, input);
	length = print_string(str);
	free(str);
	return (length);
}
