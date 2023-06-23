/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:20:07 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/04/08 13:31:26 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	print_format(va_list args, const char id)
{
	int	printed;

	printed = 0;
	if (id == 'c')
		printed += ft_printchar(va_arg(args, int));
	if (id == 's')
		printed += ft_print_str(va_arg(args, char *));
	if (id == 'p')
		printed += ft_print_addr(va_arg(args, unsigned long));
	if (id == 'd' || id == 'i')
		printed += ft_printnbr(va_arg(args, int));
	if (id == 'u')
		printed += ft_printunbr(va_arg(args, unsigned int));
	if (id == 'x' || id == 'X')
		printed += ft_printhex(va_arg(args, unsigned int), id);
	if (id == '%')
		printed += ft_printchar('%');
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += print_format(args, str[i + 1]);
			i++;
		}
		else
		{
			length += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (length);
}
