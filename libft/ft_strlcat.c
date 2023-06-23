/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:53:37 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/09/24 14:33:38 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_char(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			size_src;
	size_t			size_dest;

	i = 0;
	j = 0;
	size_src = ft_count_char((char *)src);
	size_dest = ft_count_char((char *)dest);
	while (dest[i] > 0 && i < size)
		i++;
	while (i < size - 1 && size != 0 && src[j] > 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (size <= size_dest)
		return (size_src + size);
	else
	{
		dest[i] = '\0';
		return (size_dest + size_src);
	}
}
