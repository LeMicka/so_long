/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_resolvable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:45:02 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/05 17:12:07 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char    **map_copy(t_map *map_struct)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (map_struct->height));
	i = 0;
	while (i < map_struct->height)
	{
		map_copy[i] = (char *)calloc(sizeof(char), map_struct->width + 1);
		ft_memmove(map_copy[i], map_struct->map[i], map_struct->width);
		i++;
	}
	return (map_copy);
}

void	map_flood(char **map_copy, int x, int y, t_check *elems)
{
	
	while (map_copy[x][y] != '1' && map_copy[x][y] != '2')
	{
		if (map_copy[x][y] == 'E')
			elems->nb_exit++;
		else if (map_copy[x][y] == 'C')
			elems->nb_collectibles++;
		map_copy[x][y] = '2';
		map_flood(map_copy, x + 1, y, elems);
		map_flood(map_copy, x - 1, y, elems);
		map_flood(map_copy, x, y + 1, elems);
		map_flood(map_copy, x, y - 1, elems);
	}
}

t_check	*check_init(t_check *elems)
{
	elems = (t_check *)malloc(sizeof(t_check));
	if (!elems)
        return(NULL);
	elems->nb_collectibles = 0;
	elems->nb_exit = 0;
	elems->nb_player = 0;
	return (elems);
}

bool    map_resolvable(t_map *map_struct)
{
	char		**map_cpy;
	t_check 	*elems;
	bool		err;

	err = 0;
	map_cpy = NULL;
	elems = NULL;
	elems = check_init(elems);
	map_cpy = map_copy(map_struct);
	map_flood(map_cpy, map_struct->start_i, map_struct->start_j, elems);
	if(elems->nb_exit != map_struct->exit)
		err = 1;
	if(elems->nb_collectibles != map_struct->collectibles)
		err = 1;
	ft_free_tab(map_cpy, map_struct->height);
	free(elems);
	return (err);
}


