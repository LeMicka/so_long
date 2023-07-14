/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_resolvable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:45:02 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/14 14:55:20 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**map_copy(t_game *game_struct)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (game_struct->height));
	i = 0;
	while (i < game_struct->height)
	{
		map_copy[i] = (char *)calloc(sizeof(char), game_struct->width + 1);
		ft_memmove(map_copy[i], game_struct->map[i], game_struct->width);
		i++;
	}
	return (map_copy);
}

void	map_flood(char **map_copy, int i, int j, t_check *elems)
{
	while (map_copy[i][j] != '1' && map_copy[i][j] != '2')
	{
		if (map_copy[i][j] == 'E')
			elems->nb_exit++;
		else if (map_copy[i][j] == 'C')
			elems->nb_collectibles++;
		map_copy[i][j] = '2';
		map_flood(map_copy, i + 1, j, elems);
		map_flood(map_copy, i - 1, j, elems);
		map_flood(map_copy, i, j + 1, elems);
		map_flood(map_copy, i, j - 1, elems);
	}
}

t_check	*check_init(t_check *elems)
{
	elems = (t_check *)malloc(sizeof(t_check));
	if (!elems)
		return (NULL);
	elems->nb_collectibles = 0;
	elems->nb_exit = 0;
	elems->nb_player = 0;
	return (elems);
}

bool	map_resolvable(t_game *game_struct)
{
	char		**map_cpy;
	t_check		*elems;
	bool		err;

	err = 0;
	map_cpy = NULL;
	elems = NULL;
	elems = check_init(elems);
	map_cpy = map_copy(game_struct);
	map_flood(map_cpy, game_struct->player_i, game_struct->player_j, elems);
	if (elems->nb_exit != game_struct->nb_exit)
		err = 1;
	if (elems->nb_collectibles != game_struct->nb_collectibles)
		err = 1;
	ft_free_tab(map_cpy, game_struct->height);
	free(elems);
	return (err);
}
