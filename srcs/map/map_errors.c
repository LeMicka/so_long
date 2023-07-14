/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:26:22 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/13 13:00:54 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_error_messages(t_game *game_struct, char *error_message)
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
	ft_free_tab(game_struct->map, game_struct->height);
	free(game_struct);
	exit(1);
}

bool	map_components(t_game *game_struct)
{
	int i;
	int j;

	i = 0;
	while (game_struct->map[i])
	{
		j = 0;
		while (game_struct->map[i][j])
		{
			if (game_struct->map[i][j] == 'P' && game_struct->player == 0)
			{
				game_struct->nb_player++;
				game_struct->player_i = i;
				game_struct->player_j = j;
			}
			else if (game_struct->map[i][j] == 'E' && game_struct->nb_exit == 0)
			{
				game_struct->nb_exit++;
				game_struct->e_i = i;
				game_struct->e_j = j;
			}
			else if (game_struct->map[i][j] == 'C')
				game_struct->nb_collectibles++;
			else if (game_struct->map[i][j] != '1' && game_struct->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if (game_struct->nb_collectibles == 0 || game_struct->nb_exit != 1 || game_struct->nb_player != 1)
		return (1);
	return (0);
}

bool	check_borders(t_game *game_struct)
{
	int i;

	i = 0;
	while (game_struct->map[i])
	{
		if(game_struct->map[i][0] != '1' || game_struct->map[i][game_struct->width - 1] != '1')
			return(1);
		i++;
	}
	i = 0;
	while (game_struct->map[0][i])
	{
		if(game_struct->map[0][i] != '1' || game_struct->map[game_struct->height - 1][i] != '1')
			return(1);
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
