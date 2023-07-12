/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:59:11 by yorlians          #+#    #+#             */
/*   Updated: 2023/02/25 14:15:58 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_input(va_list arg, int i, const char *input)
{
	char	*x;
	char	*upper_x;

	x = "0123456789abcdef";
	upper_x = "0123456789ABCDEF";
	if (input[i + 1] == 'c')
		return (print_char(va_arg(arg, int)));
	if (input[i + 1] == 's')
		return (print_string(va_arg(arg, char *)));
	if (input[i + 1] == 'p')
		return (write(1, "0x", 2) + print_ptr(va_arg(arg, unsigned long *), x));
	if (input[i + 1] == 'd')
		return (print_int(va_arg(arg, int)));
	if (input[i + 1] == 'i')
		return (print_int(va_arg(arg, int)));
	if (input[i + 1] == 'u')
		return (print_unsigned_int(va_arg(arg, unsigned int)));
	if (input[i + 1] == 'x')
		return (print_hex(va_arg(arg, unsigned int), x));
	else if (input[i + 1] == 'X')
		return (print_hex(va_arg(arg, unsigned int), upper_x));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		length;
	int		i;

	length = 0;
	i = 0;
	va_start(arg, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%' && locate_formats("cspdiuxX%", input[i + 1]))
		{
			length += check_input(arg, i, input);
			i++;
			if (input[i] == '%')
				length += print_char('%');
		}
		else
			length += print_char(input[i]);
		i++;
	}
	va_end(arg);
	return (length);
}

char	*locate_formats(const char *str, int formats)
{
	while (*str)
	{
		if (*str == formats)
			return ((char *)str);
		str++;
	}
	if (formats == '\0')
		return ((char *)str);
	return (0);
}
