/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:40:41 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/23 12:09:24 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buf_append(t_buffer *buffer, char *buf_read, ssize_t mem_read)
{
	ssize_t	i;
	char	*new_buf;

	i = 0;
	new_buf = malloc(buffer->len + mem_read);
	if (!new_buf)
	{
		set_buffer(buffer, NULL, 0);
		return ;
	}
	while ((size_t)i < (buffer->len))
	{
		new_buf[i] = (buffer->buf)[i];
		i++;
	}
	while ((size_t)i < mem_read + (buffer->len))
	{
		new_buf[i] = buf_read[i - (buffer->len)];
		i++;
	}
	set_buffer(buffer, new_buf, mem_read + buffer->len);
}

int	buf_update(t_buffer *buffer)
{
	size_t	nl;
	char	*new_buffer;
	size_t	i;

	nl = ft_strchr_gnl(buffer->buf, '\n', buffer->len);
	if (nl == 0 || buffer->len == nl)
	{
		set_buffer(buffer, NULL, 0);
		return (0);
	}
	new_buffer = malloc(buffer->len - nl);
	if (!new_buffer)
	{
		set_buffer(buffer, NULL, 0);
		return (1);
	}
	i = 0;
	while (i < (buffer->len - nl))
	{
		new_buffer[i] = buffer->buf[nl + i];
		i++;
	}
	set_buffer(buffer, new_buffer, i);
	return (0);
}

char	*buf_extract(t_buffer buffer)
{
	size_t	nl;
	char	*line;
	size_t	i;
	size_t	x;

	nl = ft_strchr_gnl(buffer.buf, '\n', buffer.len);
	if (nl == 0)
		x = buffer.len + 1;
	else
		x = nl + 1;
	line = malloc(x);
	if (!line)
		return (NULL);
	i = 0;
	while (i < (x - 1))
	{
		line[i] = buffer.buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	read_line(int fd, t_buffer *buffer)
{
	ssize_t	mem_read;
	char	*buf_read;
	int		x;

	mem_read = 1;
	buf_read = malloc(BUFFER_SIZE);
	if (!buf_read)
	{
		set_buffer(buffer, NULL, 0);
		return ;
	}
	while (mem_read > 0)
	{
		mem_read = read(fd, buf_read, BUFFER_SIZE);
		x = buf_expand(mem_read, buf_read, buffer);
		if (x == 0)
			return ;
		if (ft_strchr_gnl(buf_read, '\n', mem_read) != 0)
			break ;
	}
	free(buf_read);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer[OPEN_MAX];
	char			*line;
	int				update_fail;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_line(fd, &(buffer[fd]));
	if (buffer[fd].buf == NULL)
		return (NULL);
	line = buf_extract(buffer[fd]);
	if (!line)
	{
		free(buffer[fd].buf);
		buffer[fd].buf = NULL;
		buffer[fd].len = 0;
		return (NULL);
	}
	update_fail = buf_update(&(buffer[fd]));
	if (update_fail == 1)
	{
		free(line);
		line = NULL;
	}
	return (line);
}
