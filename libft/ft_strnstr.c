/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:33:24 by mbruzzi           #+#    #+#             */
/*   Updated: 2022/09/24 14:27:05 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfound(char *str, char *needle, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (str[i] == needle[j])
	{
		i++;
		j++;
		if (needle[j] == '\0')
			return (1);
		if (i == len)
			return (0);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	int			found;

	i = 0;
	found = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
			found = ft_strfound((char *)haystack, (char *)needle, i, len);
		if (found == 1)
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	if ((haystack[i] == '\0' || i == len) && found == 0)
		return (NULL);
	return ((char *)haystack);
}

//  