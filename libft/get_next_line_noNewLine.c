/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_noNewLine.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:04:16 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/06/29 20:34:04 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_updatebuf(char *buffer)
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

static char	*ft_line(char *buffer)
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
		line[j] = '\0';
	return (line);
}

static char	*ft_newbuffer(char *buff1, char *buff2)
{
	char	*buffer;

	buffer = ft_strjoin(buff1, buff2);
	free(buff1);
	return (buffer);
}

static char	*read_line(int fd, char *buffer)
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

int	get_next_line_nonew(int fd, char **line)
{
	static char	*buffer;
	char		*tmp;
	int			status;

	status = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (0);
	tmp = ft_line(buffer);
	buffer = ft_updatebuf(buffer);
	if (tmp == NULL)
		return (0);
	*line = tmp;
	return (status);
}
