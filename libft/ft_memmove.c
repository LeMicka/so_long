/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:30:43 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/09/24 14:25:02 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*src2;
	char	*dst2;

	src2 = (char *)src;
	dst2 = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len--)
			dst2[len] = src2[len];
	}
	else if (dst <= src)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}
