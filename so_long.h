/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:27:09 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/13 22:42:17 by mbruzzi          ###   ########.fr       */
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
	mlx_image_t		*wall;
	mlx_image_t		*empty;
	mlx_image_t		*objective;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
}   t_game;

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


void		map_init(char *argv[], t_game *game_struct);
void	    map_errors(t_game *game_struct);
void	    map_error_messages(t_game *game_struct, char *error_message);
t_game      *create_struct(t_game *game_struct);
bool        map_resolvable(t_game *game_struct);
void	    map_free(char **tab, int height);
void		get_img_struct(t_game *game_struct);
void	    put_imgs(t_game *game_struct);
void		ft_move(mlx_key_data_t keydata, void *param);
void		window_close(t_game *game_struct);

#endif