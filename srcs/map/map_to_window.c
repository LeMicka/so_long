/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:24:39 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/10 13:09:42 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	window_close(t_images *images, mlx_t *mlx, t_textures *textures)
{
	mlx_delete_image(mlx, images->empty);
	mlx_delete_image(mlx, images->wall);
	mlx_delete_image(mlx, images->collectible);
	mlx_delete_image(mlx, images->objective);
	mlx_delete_image(mlx, images->player);
	mlx_delete_texture(textures->empty);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->objective);
	mlx_delete_texture(textures->player);
}

void	put_imgs(t_map *map_str, t_images *images, mlx_t *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_str->height)
	{
		
		j = 0;
		while (j < map_str->width)
		{
			if (map_str->map[i][j] == '1')
				mlx_image_to_window(mlx, images->wall, j * TILE_WIDTH , i * TILE_HEIGHT);
			else
				mlx_image_to_window(mlx, images->empty, j * TILE_WIDTH , i * TILE_HEIGHT);
			if (map_str->map[i][j] == 'C')
				mlx_image_to_window(mlx, images->collectible, j * TILE_WIDTH , i * TILE_HEIGHT);
			if (map_str->map[i][j] == 'E')
				mlx_image_to_window(mlx, images->objective, j * TILE_WIDTH , i * TILE_HEIGHT);
			if (map_str->map[i][j] == 'P')
				mlx_image_to_window(mlx, images->player, j * TILE_WIDTH , i * TILE_HEIGHT);
			j++;
		}
		i++;
	}
}

t_images	*images_create(t_textures *textures, t_images *images, mlx_t *mlx)
{
	images = (t_images *)malloc(sizeof(t_images));
	if (!images)
		return(NULL);
	images->empty = mlx_texture_to_image(mlx, textures->empty);
	if (!images->empty)
		return (NULL);
	if (!mlx_resize_image(images->empty, TILE_WIDTH, TILE_HEIGHT))
		return (NULL);
	images->wall = mlx_texture_to_image(mlx, textures->wall);
	if (!images->wall)
		return (NULL);
	if (!mlx_resize_image(images->wall, TILE_WIDTH, TILE_HEIGHT))
		return (NULL);
	images->collectible = mlx_texture_to_image(mlx, textures->collectible);
	if (!images->collectible)
		return (NULL);
	if (!mlx_resize_image(images->collectible, TILE_WIDTH, TILE_HEIGHT))
		return (NULL);
	images->objective = mlx_texture_to_image(mlx, textures->objective);
	if (!images->objective)
		return (NULL);
	if (!mlx_resize_image(images->objective, TILE_WIDTH, TILE_HEIGHT))
		return (NULL);
	images->player = mlx_texture_to_image(mlx, textures->player);
	if (!images->player)
		return (NULL);
	if (!mlx_resize_image(images->player, TILE_WIDTH, TILE_HEIGHT))
		return (NULL);
	return (images);
}

t_textures	*textures_create(t_textures *textures)
{
	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		return(NULL);
	textures->empty = mlx_load_png("/home/mbruzzi/so_long2/assets/empty.png");
	textures->wall = mlx_load_png("/home/mbruzzi/so_long2/assets/walls.png");
	textures->collectible = mlx_load_png("/home/mbruzzi/so_long2/assets/collectibles.png");
	textures->objective = mlx_load_png("/home/mbruzzi/so_long2/assets/objective.png");
	textures->player = mlx_load_png("/home/mbruzzi/so_long2/assets/player.png");
	return (textures);
}

void	map_to_window(t_map *map_str, mlx_t *mlx)
{
	t_textures	*textures;
	t_images	*images;

	textures = NULL;
	images = NULL;
	textures = textures_create(textures);
	images = images_create(textures, images, mlx);
	//ft_printf("%i, width\n", WIDTH / map_str->width);
	//ft_printf("%i, height\n", HEIGHT / map_str->height);
	put_imgs(map_str, images, mlx);
	
	mlx_loop(mlx);
	window_close(images, mlx, textures);
	free(textures);
	free(images);
}