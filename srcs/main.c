/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:19:16 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/18 09:58:58 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_extension(char *map_name)
{
	char	**map_separated;

	map_separated = ft_split(map_name, '.');
	if (!ft_strcmp(map_separated[1], ".ber"))
	{
		ft_free_tab(map_separated, 0);
		ft_printf("ERROR: map %s doesn't have the '.ber' extension\n", map_name);
		exit(0);
	}
	ft_free_tab(map_separated, 0);
}

void	window_close(t_game *game_struct)
{
	mlx_delete_image(game_struct->mlx, game_struct->empty);
	mlx_delete_image(game_struct->mlx, game_struct->wall);
	mlx_delete_image(game_struct->mlx, game_struct->coll);
	mlx_delete_image(game_struct->mlx, game_struct->obj);
	mlx_delete_image(game_struct->mlx, game_struct->player);
}

void	put_imgs(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			if (g->map[i][j] == '1')
				mlx_image_to_window(g->mlx, g->wall, j * TILE_W, i * TILE_H);
			else
				mlx_image_to_window(g->mlx, g->empty, j * TILE_W, i * TILE_H);
			if (g->map[i][j] == 'C')
				mlx_image_to_window(g->mlx, g->coll, j * TILE_W, i * TILE_H);
			if (g->map[i][j] == 'E')
				mlx_image_to_window(g->mlx, g->obj, j * TILE_W, i * TILE_H);
			if (g->map[i][j] == 'P')
				mlx_image_to_window(g->mlx, g->player, j * TILE_W, i * TILE_H);
			j++;
		}
		i++;
	}
}

void	game(t_game *g)
{
	g->mlx = mlx_init(TILE_W * g->width, TILE_H * g->height, "MLX42", true);
	get_img_struct(g);
	put_imgs(g);
	mlx_key_hook(g->mlx, &ft_move, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	ft_free_tab(g->map, g->height);
	free(g);
}

int	main(int argc, char **argv)
{
	t_game		*game_struct;

	game_struct = NULL;
	if (argc != 2)
	{
		ft_printf("So_long -> USAGE ERROR: ./so_long <map.ber>");
		exit(0);
	}
	check_extension(argv[1]);
	game_struct = create_struct(game_struct);
	map_init(argv, game_struct);
	map_errors(game_struct);
	game(game_struct);
	return (EXIT_SUCCESS);
}
