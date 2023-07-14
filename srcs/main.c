// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../so_long.h"


/* void	ft_hook(void *param)
{
	t_game *game_struct;

	game_struct = param;

	if (mlx_is_key_down(game_struct->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game_struct->mlx);
	if (mlx_is_key_down(game_struct->mlx, MLX_KEY_UP))
		images->player->instances[0].y -= 1;
	if (mlx_is_key_down(game_struct->mlx, MLX_KEY_DOWN))
		images->player->instances[0].y += 1;
	if (mlx_is_key_down(game_struct->mlx, MLX_KEY_LEFT))
		images->player->instances[0].x -= 1;
	if (mlx_is_key_down(game_struct->mlx, MLX_KEY_RIGHT))
		images->player->instances[0].x += 1;
} */

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
	mlx_delete_image(game_struct->mlx, game_struct->collectible);
	mlx_delete_image(game_struct->mlx, game_struct->objective);
	mlx_delete_image(game_struct->mlx, game_struct->player);
}

void	put_imgs(t_game *game_struct)
{
	int	i;
	int	j;

	i = 0;
	while (i < game_struct->height)
	{
		j = 0;
		while (j < game_struct->width)
		{
			if (game_struct->map[i][j] == '1')
				mlx_image_to_window(game_struct->mlx, game_struct->wall, j * TILE_WIDTH , i * TILE_HEIGHT);
			else
				mlx_image_to_window(game_struct->mlx, game_struct->empty, j * TILE_WIDTH , i * TILE_HEIGHT);
			if (game_struct->map[i][j] == 'C')
				mlx_image_to_window(game_struct->mlx, game_struct->collectible, j * TILE_WIDTH , i * TILE_HEIGHT);
			if (game_struct->map[i][j] == 'E')
				mlx_image_to_window(game_struct->mlx, game_struct->objective, j * TILE_WIDTH , i * TILE_HEIGHT);
			if (game_struct->map[i][j] == 'P')
				mlx_image_to_window(game_struct->mlx, game_struct->player, j * TILE_WIDTH , i * TILE_HEIGHT);
			j++;
		}
		i++;
	}
}

void	game(t_game *game_struct)
{
	/* int i = 0;
	while (i < game_struct->height)
	{
		ft_printf("%s\n", game_struct->map[i]);
		i++;
	} */
	game_struct->mlx = mlx_init(TILE_WIDTH * game_struct->width, TILE_HEIGHT * game_struct->height, "MLX42", true);
	get_img_struct(game_struct);
	put_imgs(game_struct);
	mlx_key_hook(game_struct->mlx, &ft_move, game_struct);
	mlx_loop(game_struct->mlx);
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
	/* mlx_texture_t* texture = mlx_load_png("./assets/walls.png");
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, WIDTH / map_struct->width, HEIGHT / map_struct->height);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture); */
	mlx_terminate(game_struct->mlx);
	
	ft_free_tab(game_struct->map, game_struct->height);
	free(game_struct);
	
	return (EXIT_SUCCESS);
}
