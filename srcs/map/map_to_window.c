/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:24:39 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/18 09:59:33 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_textures	*textures_create(t_textures *textures)
{
	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->empty = mlx_load_png("./assets/empty.png");
	textures->wall = mlx_load_png("./assets/walls.png");
	textures->collectible = mlx_load_png("./assets/collectibles.png");
	textures->objective = mlx_load_png("./assets/objective.png");
	textures->player = mlx_load_png("./assets/player.png");
	return (textures);
}

void	get_img_struct(t_game *game)
{
	t_textures	*textures;

	textures = NULL;
	textures = textures_create(textures);
	game->empty = mlx_texture_to_image(game->mlx, textures->empty);
	mlx_resize_image(game->empty, TILE_W, TILE_H);
	game->wall = mlx_texture_to_image(game->mlx, textures->wall);
	mlx_resize_image(game->wall, TILE_W, TILE_H);
	game->coll = mlx_texture_to_image(game->mlx, textures->collectible);
	mlx_resize_image(game->coll, TILE_W, TILE_H);
	game->obj = mlx_texture_to_image(game->mlx, textures->objective);
	mlx_resize_image(game->obj, TILE_W, TILE_H);
	game->player = mlx_texture_to_image(game->mlx, textures->player);
	mlx_resize_image(game->player, TILE_W, TILE_H);
	mlx_delete_texture(textures->empty);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->objective);
	mlx_delete_texture(textures->player);
	free(textures);
}
