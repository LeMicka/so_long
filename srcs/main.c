// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../so_long.h"


#define BPP sizeof(int32_t)
 
#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize()
{
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	 t_map	*map_struct;
	
	if (argc != 2)
	{
		ft_printf("So_long -> USAGE ERROR: ./so_long <map.ber>");
		exit(0);
	}
	map_struct = map_init(argv);
	map_errors(map_struct);
	
	if (!(mlx = mlx_init(TILE_WIDTH * map_struct->width, TILE_HEIGHT * map_struct->height, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	map_to_window(map_struct, mlx);
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
	mlx_terminate(mlx);
	
	ft_free_tab(map_struct->map, map_struct->height);
	free(map_struct);
	return (EXIT_SUCCESS);
}
