/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:27:09 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/10 13:03:39 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/include/MLX42/MLX42.h"
# include <fcntl.h>

# ifndef WIDTH
#  define TILE_WIDTH 52
# endif

# ifndef HEIGHT
#  define TILE_HEIGHT 52
# endif

typedef struct s_map
{
    int     height;
    int     width;
    char    **map;
    int     player;
    int     exit;
    int     collectibles;
    int     start_i;
    int     start_j;
}   t_map;

typedef struct s_check
{
    int nb_player;
    int nb_exit;
    int nb_collectibles;
}   t_check;

typedef struct s_textures
{
    mlx_texture_t   *wall;
    mlx_texture_t   *empty;
    mlx_texture_t   *objective;
    mlx_texture_t   *collectible;
    mlx_texture_t   *player;
}   t_textures;

typedef struct s_images
{
    mlx_image_t   *wall;
    mlx_image_t   *empty;
    mlx_image_t   *objective;
    mlx_image_t   *collectible;
    mlx_image_t   *player;
}   t_images;

t_map	*map_init(char *argv[]);
void	map_errors(t_map *map_struct);
void	map_error_messages(t_map *map_struct, char *error_message);
t_map   *create_struct(t_map *map_struct);
bool    map_resolvable(t_map *map_struct);
void	map_free(char **tab, int height);
void	map_to_window(t_map *map_str, mlx_t *mlx);

#endif