/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:24:39 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/14 12:55:15 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* t_images	*images_create(t_textures *textures, t_images *images, mlx_t *mlx)
{
	images = (t_images *)malloc(sizeof(t_images));
	if (!images)
		return(NULL);
	images->empty = mlx_texture_to_image(mlx, textures->empty);
	mlx_resize_image(images->empty, TILE_WIDTH, TILE_HEIGHT);
	images->wall = mlx_texture_to_image(mlx, textures->wall);
	mlx_resize_image(images->wall, TILE_WIDTH, TILE_HEIGHT);
	images->collectible = mlx_texture_to_image(mlx, textures->collectible);
	mlx_resize_image(images->collectible, TILE_WIDTH, TILE_HEIGHT);
	images->objective = mlx_texture_to_image(mlx, textures->objective);
	mlx_resize_image(images->objective, TILE_WIDTH, TILE_HEIGHT);
	images->player = mlx_texture_to_image(mlx, textures->player);
	mlx_resize_image(images->player, TILE_WIDTH, TILE_HEIGHT);
	mlx_delete_texture(textures->empty);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->objective);
	mlx_delete_texture(textures->player);
	free(textures);
	return (images);
} */

t_textures	*textures_create(t_textures *textures)
{
	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		return(NULL);
	textures->empty = mlx_load_png("/Users/mbruzzi/Cursus/so_long/assets/empty.png");
	textures->wall = mlx_load_png("/Users/mbruzzi/Cursus/so_long/assets/walls.png");
	textures->collectible = mlx_load_png("/Users/mbruzzi/Cursus/so_long/assets/collectibles.png");
	textures->objective = mlx_load_png("/Users/mbruzzi/Cursus/so_long/assets/objective.png");
	textures->player = mlx_load_png("/Users/mbruzzi/Cursus/so_long/assets/player.png");
	return (textures);
}

void	get_img_struct(t_game *game)
{
	t_textures	*textures;

	textures = NULL;
	textures = textures_create(textures);
	game->empty = mlx_texture_to_image(game->mlx, textures->empty);
	mlx_resize_image(game->empty, TILE_WIDTH, TILE_HEIGHT);
	game->wall = mlx_texture_to_image(game->mlx, textures->wall);
	mlx_resize_image(game->wall, TILE_WIDTH, TILE_HEIGHT);
	game->collectible = mlx_texture_to_image(game->mlx, textures->collectible);
	mlx_resize_image(game->collectible, TILE_WIDTH, TILE_HEIGHT);
	game->objective = mlx_texture_to_image(game->mlx, textures->objective);
	mlx_resize_image(game->objective, TILE_WIDTH, TILE_HEIGHT);
	game->player = mlx_texture_to_image(game->mlx, textures->player);
	mlx_resize_image(game->player, TILE_WIDTH, TILE_HEIGHT);
	mlx_delete_texture(textures->empty);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->objective);
	mlx_delete_texture(textures->player);
	free(textures);
}
