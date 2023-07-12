/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:15:32 by yorlians          #+#    #+#             */
/*   Updated: 2023/02/25 16:04:04 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len_for_itoa(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*itoa(long n)
{
	int		length;
	char	*str;

	length = get_len_for_itoa(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (str);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	str[length--] = '\0';
	while (n != 0)
	{
		str[length] = (char)(n % 10) + '0';
		length--;
		n = n / 10;
	}
	return (str);
}

int	print_int(int n)
{
	int		length;
	char	*number;

	length = 0;
	number = itoa(n);
	length = print_string(number);
	free(number);
	return (length);
}
