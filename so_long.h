/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:27:09 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/17 16:37:22 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

# define TILE_W 52
# define TILE_H 52

typedef struct s_game
{
	mlx_t			*mlx;
	int				height;
	int				width;
	char			**map;
	int				nb_player;
	int				nb_exit;
	int				nb_collectibles;
	int				player_i;
	int				player_j;
	int				next_i;
	int				next_j;
	int				e_i;
	int				e_j;
	int				nb_moves;
	mlx_image_t		*wall;
	mlx_image_t		*empty;
	mlx_image_t		*obj;
	mlx_image_t		*coll;
	mlx_image_t		*player;
}	t_game;

typedef struct s_check
{
	int	nb_player;
	int	nb_exit;
	int	nb_collectibles;
}	t_check;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*empty;
	mlx_texture_t	*objective;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
}	t_textures;

void		map_init(char *argv[], t_game *game_struct);
void		map_errors(t_game *game_struct);
void		map_error_messages(t_game *game_struct, char *error_message);
t_game		*create_struct(t_game *game_struct);
bool		map_resolvable(t_game *game_struct);
void		map_free(char **tab, int height);
void		get_img_struct(t_game *game_struct);
void		put_imgs(t_game *game_struct);
void		ft_move(mlx_key_data_t keydata, void *param);
void		window_close(t_game *game_struct);
void		*my_malloc(size_t size, const char *file, int line, const char *func);
void		my_free(void *ptr, const char *file, int line, const char *func);

#endif