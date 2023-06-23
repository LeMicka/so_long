/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:01 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/04/08 13:33:00 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_printnbr(int n)
{
	unsigned int	number;
	int				len;

	len = get_length((long)n);
	if (n < 0)
	{
		ft_printchar('-');
		number = -n;
	}
	else
		number = n;
	if (number > 9)
	{
		ft_printnbr(number / 10);
		number %= 10;
	}
	ft_printchar(number + '0');
	return (len);
}

int	ft_printunbr(unsigned int n)
{
	int				len;

	len = get_length((long)n);
	if (n > 9)
	{
		ft_printnbr(n / 10);
		n %= 10;
	}
	ft_printchar(n + '0');
	return (len);
}
