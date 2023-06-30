/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:23:21 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/06/30 13:15:44 by mbruzzi          ###   ########.fr       */
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
	ft_printf("gnlnb1\n");
	buffer = ft_strjoin(buff1, buff2);
	ft_printf("gnlnb2\n");
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
		ft_printf("gnlr1\n");
		read_status = read(fd, line, BUFFER_SIZE);
		ft_printf("gnlr2\n");
		if (read_status == -1)
		{
			free (line);
			free (buffer);
			return (NULL);
		}
		ft_printf("gnlr3\n");
		line[read_status] = '\0';
		ft_printf("gnlr4\n");
		buffer = ft_newbuffer(buffer, line);
		ft_printf("gnlr5\n");
		if (ft_strchr(line, '\n'))
			break ;
		ft_printf("gnlr6\n");
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
	ft_printf("gnl1\n");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_printf("gnl2\n");
	buffer = read_line(fd, buffer);
	ft_printf("gnl3\n");
	if (!buffer)
		return (NULL);
	ft_printf("gnl4\n");
	tmp = ft_line(buffer);
	ft_printf("gnl5\n");
	buffer = ft_updatebuf(buffer);
	ft_printf("gnl6\n");
	return (tmp);
}
