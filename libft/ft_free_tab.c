/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:17:57 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/05 12:44:15 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab, int rows)
{
	int	i;

	i = 0;
	if (rows == 0)
	{
		while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	}
	else
	{
	while (i < rows)
	{
		free(tab[i]);
		i++;
	}
	}
	free(tab);
}
