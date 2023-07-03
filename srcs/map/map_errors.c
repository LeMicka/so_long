/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:26:22 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/03 14:26:16 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_error_messages(t_map *map_struct, char *error_message)
{
	if (!ft_strcmp(error_message, "NON_UNIFORM_MAP"));
		ft_putstr_fd("ERROR\n%s:the provided map is not uniform", 2);
	ft_free_tab(map_struct->map);
	free(map_struct);
	exit(1);
}

bool	check_borders(char **map)
{
	int i;
	int j;

}

void	map_errors(t_map *map_struct)
{
	
	/* if (check_borders(map_struct->map))
		map_error_messages(map_struct, ) */
}
