/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:23:21 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/18 11:33:47 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_updatebuf(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(((ft_strlen(buffer) - i) + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (new_buffer);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] && buffer[j] == '\n')
		line[j] = '\n';
	return (line);
}

char	*ft_newbuffer(char *buff1, char *buff2)
{
	char	*buffer;

	buffer = ft_strjoin(buff1, buff2);
	free(buff1);
	return (buffer);
}

char	*read_line(int fd, char *buffer)
{
	char		*line;
	ssize_t		read_status;

	line = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!line)
		return (NULL);
	read_status = 1;
	while (read_status > 0)
	{
		read_status = read(fd, line, BUFFER_SIZE);
		if (read_status == -1)
		{
			free (line);
			free (buffer);
			return (NULL);
		}
		line[read_status] = '\0';
		buffer = ft_newbuffer(buffer, line);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free (line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;

	if (!buffer)
		buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	tmp = ft_line(buffer);
	buffer = ft_updatebuf(buffer);
	return (tmp);
}
