/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:25:21 by jv                #+#    #+#             */
/*   Updated: 2022/06/11 22:16:05 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

static char	*dump_line(char **rest, char *content)
{
	char	*ptr_aux;

	if (!*rest)
		*rest = content;
	else
	{
		ptr_aux = *rest;
		*rest = ft_strjoin(*rest, content);
		free(ptr_aux);
	}
	return (*rest);
}

char	*ft_strdup(const char *str)
{
	size_t	size_buffer;
	char	*new_str;

	size_buffer = ft_strlen(str) + 1;
	new_str = (char *) malloc(size_buffer);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str, size_buffer);
	return (new_str);
}

static char	*read_lines(char **buffer, char *f)
{
	int		length;
	char	*pos_char;
	int		size;
	char	*tmp;
	char	ch;

	pos_char = ft_strchr(*buffer, '\n');
	size = ft_strlen(*buffer);
	ch = '\0';
	if (size > 0)
	{
		if (!pos_char)
		{
			tmp = ft_strdup(*buffer);
			ft_memcpy(*buffer, &ch, BUFFER_SIZE);
			return (tmp);
		}
		*f = 1;
		length = (int)(pos_char - *buffer);
		tmp = (char *)ft_calloc(length + 1, 1);
		ft_memcpy(tmp, *buffer, length);
		tmp[length] = '\0';
		ft_memcpy(*buffer, (*buffer + length + 1), size - length + 1);
	}
	return (tmp);
}

static char	*get_word(char **rest, char *buffer, int fd)
{
	char	*content;
	char	flag;

	flag = 0;
	while (1)
	{
		if (ft_strlen(buffer) > 0)
			content = read_lines(&buffer, &flag);
		else
		{
			if (read(fd, buffer, BUFFER_SIZE) < 1)
				break ;
			buffer[BUFFER_SIZE] = '\0';
			content = read_lines(&buffer, &flag);
		}
		dump_line(rest, content);
		if (flag)
			return (*rest);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*rest[MAX_FD];
	int			pos;

	if (!buffer)
		buffer = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
	pos = fd % (MAX_FD - 1);
	rest[pos] = NULL;
	get_word((rest + pos), buffer, fd);
	if (!rest[pos])
		return (rest[pos]);
	if (!(ft_strlen(buffer) > 0))
	{
		free(buffer);
		buffer = NULL;
	}
	return (rest[pos]);
}
