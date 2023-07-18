/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:11:06 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/18 11:36:32 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_longer_map(char *buff1, char *buff2)
{
	char	*buffer;

	buffer = ft_strjoin(buff1, buff2);
	free(buff1);
	return (buffer);
}

char	**map_read(int fd)
{
	char	**map;
	char	*map_one_line;
	char	*tmp;
	int		i;

	tmp = "";
	map_one_line = "";
	map_one_line = get_next_line(fd);
	i = 0;
	while (tmp != NULL)
	{
		map_one_line = ft_longer_map(map_one_line, tmp);
		if (i != 0)
			free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	map = ft_split(map_one_line, '\n');
	free(map_one_line);
	return (map);
}

void	get_size(t_game *game_struct)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (game_struct->map[i])
	{
		j = 0;
		while (game_struct->map[i][j])
			j++;
		if (len == 0)
			len = j;
		if (len != j)
			map_error_messages(game_struct, "NON_UNIFORM_MAP");
		i++;
	}
	game_struct->height = i;
	game_struct->width = len;
}

/* void	ft_leaks(void)
{
	system("leaks -q so_long");
} */

void	map_init(char *argv[], t_game *game_struct)
{
	int		map_fd;

	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
	{
		ft_printf("ERROR: map %s not openable\n", argv[1]);
		exit(0);
	}
	game_struct->map = map_read(map_fd);
	get_size(game_struct);
}
