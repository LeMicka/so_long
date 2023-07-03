/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:27:09 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/03 14:25:30 by mbruzzi          ###   ########.fr       */
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
}   t_map;

t_map	*map_init(char *argv[]);
void	map_errors(t_map *map_struct);
void	map_error_messages(t_map *map_struct, char *error_message);
t_map   *create_struct(t_map *map_struct);

#endif