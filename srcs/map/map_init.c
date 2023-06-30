/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:11:06 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/06/30 13:06:18 by mbruzzi          ###   ########.fr       */
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
	int		i;

	tmp = "";
	map_one_line = "";
	ft_printf("ici");
	tmp = get_next_line(fd);
	ft_printf("ici1");
	i = 0;
	while (tmp != NULL)
	{
		map_one_line = ft_strjoin(map_one_line, tmp);
		free(tmp);
		i++;
		tmp = get_next_line(fd);
	}
	ft_printf("%s", map_one_line);
	return (map);
}

void	map_init(char *argv[])
{
	int		map_fd;
	char	**map;

	check_extension(argv[1]);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
	{
		ft_printf("ERROR: map %s not openable\n", argv[1]);
		exit(0);
	}
	map = map_read(map_fd);
}
