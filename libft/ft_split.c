/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:16:08 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/06 10:42:10 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_counter(char const *s, char c)
{
	int	substrings;
	int	i;

	i = 0;
	substrings = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			substrings++;
		i++;
	}
	return (substrings);
}

static char	*dup_cpy(const char *s, int start, size_t end)
{
	char	*sub_str;
	int		i;

	i = 0;
	sub_str = (char *)malloc(sizeof(char) * ((int)end - start + 1));
	while (start < (int)end)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		start;
	size_t	i;
	int		j;

	strings = (char **)malloc(sizeof(char *) * (split_counter(s, c) + 1));
	if (!s || !strings)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			strings[j++] = dup_cpy(s, start, i);
			start = -1;
		}
		i++;
	}
	strings[j] = 0;
	return (strings);
}
