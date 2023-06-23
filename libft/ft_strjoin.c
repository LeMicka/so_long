/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:54:10 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/04/08 19:35:03 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	newlen;
	char	*newstr;

	if (!s1 && !s2)
		return (NULL);
	newlen = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	newstr = malloc(sizeof(char) * newlen + 1);
	if (!newstr)
		return (NULL);
	ft_strcat(ft_strcpy(newstr, (char *)s1), (char *)s2);
	return (newstr);
}
