/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:27:09 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/05 12:18:48 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/include/MLX42/MLX42.h"
# include <fcntl.h>

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

t_map	*map_init(char *argv[]);
void	map_errors(t_map *map_struct);
void	map_error_messages(t_map *map_struct, char *error_message);
t_map   *create_struct(t_map *map_struct);
bool    map_resolvable(t_map *map_struct);
void	map_free(char **tab, int height);

#endif