/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:55:06 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/09/24 14:24:41 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char a[] = "hello word";
// 	char b[] = "salut c'est cool";
// 	printf ("%s \n",ft_memcpy(b, a, 5));
// 	printf ("%s \n",b);
// 	printf ("%s \n",a);
// 	return (0);
// }