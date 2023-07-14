/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:56:02 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/14 15:08:11 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

void	ft_end_game(t_game *game_struct)
{
	window_close(game_struct);
	mlx_terminate(game_struct->mlx);
	ft_free_tab(game_struct->map, game_struct->height);
	free(game_struct);
	//atexit(ft_leaks);
	exit(0);
}

void	ft_objective(t_game *game_struct, int i, int j)
{
	game_struct->map[i][j] = 'P';
	game_struct->map[game_struct->player_i][game_struct->player_j] = '0';
	game_struct->nb_moves++;
	if (game_struct->nb_collectibles == 0)
	{
		ft_putstr_fd("Congratulations, You won!", 1);
		ft_end_game(game_struct);
	}
	game_struct->player_i = i;
	game_struct->player_j = j;
}

void	ft_empty_or_coll(t_game *game_struct, int i, int j)
{
	int	player_i;
	int	player_j;

	player_i = game_struct->player_i;
	player_j = game_struct->player_j;
	if (game_struct->map[i][j] == 'C')
		game_struct->nb_collectibles--;
	if (player_i == game_struct->e_i && player_j == game_struct->e_j)
	{
		game_struct->map[game_struct->player_i][game_struct->player_i] = 'E';
		game_struct->map[i][j] = 'P';
	}
	else
	{
		game_struct->map[player_i][player_j] = '0';
		game_struct->map[i][j] = 'P';
	}
	game_struct->player_i = i;
	game_struct->player_j = j;
	game_struct->nb_moves++;
}

void	ft_move_check(t_game *game_struct)
{
	int	nb_moves;
	int	i;
	int	j;

	i = game_struct->next_i;
	j = game_struct->next_j;
	nb_moves = game_struct->nb_moves;
	if (game_struct->map[i][j] == '0' || game_struct->map[i][j] == 'C')
		ft_empty_or_coll(game_struct, i, j);
	if (game_struct->map[i][j] == 'E')
		ft_objective(game_struct, i, j);
	if (game_struct->nb_moves > nb_moves)
	{
		ft_putstr_fd("number of moves:", 1);
		ft_putnbr_fd(game_struct->nb_moves, 1);
		ft_putendl_fd("", 1);
	}
	window_close(game_struct);
	get_img_struct(game_struct);
	put_imgs(game_struct);
}

void	ft_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game_struct;

	game_struct = param;
	game_struct->next_i = game_struct->player_i;
	game_struct->next_j = game_struct->player_j;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_end_game(game_struct);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		game_struct->next_i -= 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		game_struct->next_i += 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		game_struct->next_j -= 1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		game_struct->next_j += 1;
	ft_move_check(game_struct);
}
