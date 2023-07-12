/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:58:38 by yorlians          #+#    #+#             */
/*   Updated: 2023/02/25 15:36:28 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len_for_hex(unsigned int n)
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

char	*hex_to_string(unsigned int n, char *input)
{
	int		length;
	char	*str;

	length = get_len_for_hex(n);
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

int	print_hex(unsigned int n, char *input)
{
	int		length;
	char	*number;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		number = hex_to_string(n, input);
		length = print_string(number);
		free(number);
	}
	return (length);
}
