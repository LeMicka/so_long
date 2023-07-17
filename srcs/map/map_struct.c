/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:20:00 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/17 13:37:18 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_game	*create_struct(t_game *game_struct)
{
	game_struct = (t_game *)custom_malloc(sizeof(t_game));
	if (!game_struct)
		return (NULL);
	game_struct->mlx = NULL;
	game_struct->height = 0;
	game_struct->width = 0;
	game_struct->map = NULL;
	game_struct->nb_collectibles = 0;
	game_struct->nb_exit = 0;
	game_struct->nb_player = 0;
	game_struct->player_i = 0;
	game_struct->player_j = 0;
	game_struct->next_i = 0;
	game_struct->next_j = 0;
	game_struct->e_i = 0;
	game_struct->e_j = 0;
	game_struct->nb_moves = 0;
	game_struct->coll = NULL;
	game_struct->wall = NULL;
	game_struct->player = NULL;
	game_struct->empty = NULL;
	game_struct->obj = NULL;
	return (game_struct);
}
