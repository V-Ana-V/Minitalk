/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:26:59 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/23 11:25:47 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchr_gnl(const char *buffer, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(buffer + i) == c)
			return (i + 1);
		i++;
	}
	return (0);
}

void	set_buffer(t_buffer *buffer, char *buf_buf, size_t buf_len)
{
	free(buffer->buf);
	buffer->buf = buf_buf;
	buffer->len = buf_len;
}

int	buf_expand(ssize_t mem_read, char *buf_read, t_buffer *buffer)
{
	if (mem_read == -1
		|| ((mem_read == 0) && (buffer->buf == NULL) && (buffer->len == 0)))
	{
		free(buf_read);
		set_buffer(buffer, NULL, 0);
		return (0);
	}
	buf_append(buffer, buf_read, mem_read);
	if (!(buffer->buf))
	{
		free(buf_read);
		return (0);
	}
	return (1);
}
