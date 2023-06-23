/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:48:06 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/04/08 13:33:29 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static void	hex_print(uintptr_t ptr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (ptr >= 16)
	{
		hex_print(ptr / 16);
		hex_print(ptr % 16);
	}
	else
		ft_printchar(hex[ptr]);
}

int	ft_print_addr(uintptr_t ptr)
{
	int	printed;

	printed = 0;
	printed += write(1, "0x", 2);
	if (ptr == 0)
		printed += write(1, "0", 1);
	else
	{
		hex_print(ptr);
		printed += ptrlen(ptr);
	}
	return (printed);
}
