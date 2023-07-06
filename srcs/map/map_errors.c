/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:26:22 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/06 09:58:58 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_error_messages(t_map *map_struct, char *error_message)
{
	if (!ft_strcmp(error_message, "NON_UNIFORM_MAP"))
		ft_putstr_fd("ERROR\nNON_UNIFORM_MAP: The provided map is not uniform.\n", 2);
	if (!ft_strcmp(error_message, "BORDER_ERROR"))
		ft_putstr_fd("ERROR\nBORDER_ERROR: The provided map is not closed/surrounded by walls.\n", 2);
	if (!ft_strcmp(error_message, "COMPONENT_ERROR"))
		ft_putstr_fd("ERROR\nCOMPONENTS_ERROR: The provided map has to many/little"
					 "of the required components.\nHere are the components needed:\n"
					 "The map can be composed of only these 5 characters:\n"
					 "0 for an empty space,\n"
					 "1 for a wall,\n"
					 "C for a collectible,\n"
					 "E for a map exit,\n"
					 "P for the player’s starting position.\n"
					 "The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.\n", 2);
	if (!ft_strcmp(error_message, "MAP_NOT_RESOLVABLE"))
		ft_putstr_fd("ERROR\nMAP_NOT_RESOLVABLE: Player can't access all the collectibles or the exit.\n", 2);
	ft_free_tab(map_struct->map, map_struct->height);
	free(map_struct);
	exit(1);
}

bool	map_components(t_map *map_struct)
{
	int i;
	int j;

	i = 0;
	while (map_struct->map[i])
	{
		j = 0;
		while (map_struct->map[i][j])
		{
			if (map_struct->map[i][j] == 'P' && map_struct->player == 0)
			{
				map_struct->player++;
				map_struct->start_i = i;
				map_struct->start_j = j;
			}
			else if (map_struct->map[i][j] == 'E' && map_struct->exit == 0)
				map_struct->exit++;
			else if (map_struct->map[i][j] == 'C')
				map_struct->collectibles++;
			else if (map_struct->map[i][j] != '1' && map_struct->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if (map_struct->collectibles == 0 || map_struct->exit != 1 || map_struct->player != 1)
		return (1);
	return (0);
}

bool	check_borders(t_map *map_struct)
{
	int i;

	i = 0;
	while (map_struct->map[i])
	{
		if(map_struct->map[i][0] != '1' || map_struct->map[i][map_struct->width - 1] != '1')
			return(1);
		i++;
	}
	i = 0;
	while (map_struct->map[0][i])
	{
		if(map_struct->map[0][i] != '1' || map_struct->map[map_struct->height - 1][i] != '1')
			return(1);
		i++;
	}
	return (0);
}

void	map_errors(t_map *map_struct)
{
	if (check_borders(map_struct))
		map_error_messages(map_struct, "BORDER_ERROR");
	if (map_components(map_struct))
		map_error_messages(map_struct, "COMPONENT_ERROR");
	if (map_resolvable(map_struct))
		map_error_messages(map_struct, "MAP_NOT_RESOLVABLE");
}
