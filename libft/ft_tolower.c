/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:04:30 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/09/24 14:27:14 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}
