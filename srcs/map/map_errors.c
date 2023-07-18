/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:26:22 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/18 10:51:23 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_error_messages(t_game *game_struct, char *error_message)
{
	if (!ft_strcmp(error_message, "NON_UNIFORM_MAP"))
		ft_putstr_fd("ERROR\nNON_UNIFORM_MAP: Provided map not uniform.\n", 2);
	if (!ft_strcmp(error_message, "BORDER_ERROR"))
		ft_putstr_fd("ERROR\nBORDER_ERROR:"
			" The provided map is not closed/surrounded by walls.\n", 2);
	if (!ft_strcmp(error_message, "COMPONENT_ERROR"))
		ft_putstr_fd("ERROR\n"
			"COMPONENTS_ERROR: The provided map has to many/little"
			"of the required components.\nHere are the components needed:\n"
			"The map can be composed of only these 5 characters:\n"
			"0 for an empty space,\n"
			"1 for a wall,\n"
			"C for a collectible,\n"
			"E for a map exit,\n"
			"P for the player’s starting position.\n"
			"The map must contain 1 exit,"
			" at least 1 collectible, and 1 starting position.\n", 2);
	if (!ft_strcmp(error_message, "MAP_NOT_RESOLVABLE"))
		ft_putstr_fd("ERROR\nMAP_NOT_RESOLVABLE:"
			" Player can't access all the collectibles or the exit.\n", 2);
	ft_free_tab(game_struct->map, game_struct->height);
	free(game_struct);
	exit(1);
}

bool	map_components(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P' && g->nb_player == 0)
				g->nb_player++;
			else if (g->map[i][j] == 'E' && g->nb_exit == 0)
				g->nb_exit++;
			else if (g->map[i][j] == 'C')
				g->nb_collectibles++;
			else if (g->map[i][j] != '1' && g->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if (g->nb_collectibles == 0 || g->nb_exit != 1 || g->nb_player != 1)
		return (1);
	return (0);
}

bool	check_borders(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
	{
		if (g->map[i][0] != '1' || g->map[i][g->width - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (g->map[0][i])
	{
		if (g->map[0][i] != '1' || g->map[g->height - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	map_errors(t_game *game_struct)
{
	if (check_borders(game_struct))
		map_error_messages(game_struct, "BORDER_ERROR");
	if (map_components(game_struct))
		map_error_messages(game_struct, "COMPONENT_ERROR");
	if (map_resolvable(game_struct))
		map_error_messages(game_struct, "MAP_NOT_RESOLVABLE");
}
