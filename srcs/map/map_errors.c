/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:26:22 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/03 15:25:28 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_error_messages(t_map *map_struct, char *error_message)
{
	if (!ft_strcmp(error_message, "NON_UNIFORM_MAP"));
		ft_putstr_fd("ERROR\nNON_UNIFORM_MAP: The provided map is not uniform", 2);
	if (!ft_strcmp(error_message, "BORDER_ERROR"));
		ft_putstr_fd("ERROR\nBORDER_ERROR: The provided map is not closed/surrounded by walls", 2);
	ft_free_tab(map_struct->map);
	free(map_struct);
	exit(1);
}

bool	check_borders(t_map *map_struct)
{
	int i;
	int j;

	i = 0;
	while (map_struct->map[i])
	{
		if(map_struct->map[i][0] != 1 || map_struct->map[i][map_struct->width] != 1)
			return(1);
	}
	

}

void	map_errors(t_map *map_struct)
{
	
	if (check_borders(map_struct->map))
		map_error_messages(map_struct, "BORDER_ERROR");
}
