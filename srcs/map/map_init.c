/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:11:06 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/03 14:51:50 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_extension(char *map_name)
{
	char	**map_separated;

	map_separated = ft_split(map_name, '.');
	if (!ft_strcmp(map_separated[1], ".ber"))
	{
		ft_free_tab(map_separated);
		ft_printf("ERROR: map %s doesn't have the '.ber' extension\n", map_name);
		exit(0);
	}
	ft_free_tab(map_separated);
}

char	**map_read(int fd)
{
	char	**map;
	char	*map_one_line;
	char	*tmp;
	int		status;
	int		i;

	tmp = "";
	map_one_line = "";
	tmp = get_next_line(fd);
	i = 0;
	status = 1;
	while (tmp != NULL)
	{
		map_one_line = ft_strjoin(map_one_line, tmp);
		free(tmp);
		i++;
		tmp = get_next_line(fd);
	}
	map = ft_split(map_one_line, '\n');
	return (map);
}

void	get_size(t_map *map_struct)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while(map_struct->map[i])
	{
		j = 0;
		while(map_struct->map[i][j])
			j++;
		if (len == 0)
			len = j;
		if (len != j)
			map_error_messages(map_struct, "NON_UNIFORM_MAP");
		i++;
	}
	map_struct->height = i;
	map_struct->width = len;
}

t_map	*map_init(char *argv[])
{
	int		map_fd;
	t_map	*map_struct;


	check_extension(argv[1]);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
	{
		ft_printf("ERROR: map %s not openable\n", argv[1]);
		exit(0);
	}
	map_struct = create_struct(map_struct);
	map_struct->map = map_read(map_fd);
	get_size(map_struct);
	return (map_struct);
}
