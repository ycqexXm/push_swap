/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:41:05 by yorlians          #+#    #+#             */
/*   Updated: 2023/03/20 03:54:02 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		check_input(va_list arg, int i, const char *input);
int		ft_printf(const char *input, ...);
char	*locate_formats(const char *str, int formats);

int		print_char(char c);

int		get_len_for_hex(unsigned int n);
char	*hex_to_string(unsigned int n, char *input);
int		print_hex(unsigned int n, char *input);

int		get_len_for_itoa(int n);
char	*itoa(long n);
int		print_int(int n);

int		get_len_for_ptr(unsigned long n);
char	*ptr_to_str(unsigned long n, char *input);
int		print_ptr(unsigned long *n, char *input);

int		print_string(char *str);

int		get_len_for_uitoa(unsigned int n);
char	*uitoa(unsigned int n);
int		print_unsigned_int(unsigned int n);

#endif
