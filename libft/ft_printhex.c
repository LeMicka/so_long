/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:23:39 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/04/08 13:32:18 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hexlen(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static void	hex_print(unsigned int nbr, char id)
{
	char	*hex;

	if (id == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		hex_print(nbr / 16, id);
		hex_print(nbr % 16, id);
	}
	else
		ft_printchar(hex[nbr]);
}

int	ft_printhex(unsigned int nbr, char id)
{
	int	printed;

	printed = 0;
	if (nbr == 0)
		printed += write(1, "0", 1);
	else
	{
		hex_print(nbr, id);
		printed += hexlen(nbr);
	}
	return (printed);
}
