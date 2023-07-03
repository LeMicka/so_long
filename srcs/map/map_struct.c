/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:20:00 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/03 14:50:34 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map   *create_struct(t_map *map_struct)
{
    map_struct = (t_map *)malloc(sizeof(t_map));
    if (!map_struct)
        return(NULL);
    map_struct->height = 0;
    map_struct->width = 0;
    map_struct->map = NULL;
    return (map_struct);
}
