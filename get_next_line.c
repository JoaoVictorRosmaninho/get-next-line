/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:12:42 by jv                #+#    #+#             */
/*   Updated: 2022/06/12 19:53:41 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <string.h>
#include <unistd.h>

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
		free(content);
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

	pos_char = ft_strchr(*buffer, '\n');
	size = (int) ft_strlen(*buffer);
	tmp = NULL;
	if (!pos_char)
	{
		tmp = ft_strdup(*buffer);
		ft_memset(*buffer, 0, BUFFER_SIZE + 1); 
		return (tmp);
	}
	*f = 1;
	length = (int)(pos_char - *buffer);
	tmp = (char *) malloc(length + 2);
	ft_memset(tmp, 0, length + 2);
	ft_memcpy(tmp, *buffer, (length + 1));
	tmp[length + 1] = '\0';
	ft_memcpy(*buffer, (*buffer + length + 1), size - length);
	return (tmp);
}

static void get_word(char **rest, char **buffer, int fd)
{
	char	*content;
	char	flag;
	ssize_t	bytes_read;
	
	flag = 0;
	while (1)
	{
		content = NULL;
		if (ft_strlen(*buffer) > 0)
			content = read_lines(buffer, &flag);
		else
		{
			bytes_read = read(fd, *buffer, BUFFER_SIZE);
			if (bytes_read < 1)
				break ;
			*(*buffer + bytes_read) = '\0';
			content = read_lines(buffer, &flag);
		}
		dump_line(rest, content);
		if (flag)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*rest;

	if (!buffer) 
	{
		buffer = (char *) malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
	}
	rest = NULL;
	get_word(&rest, &buffer, fd);
	if (!rest) {
		free(buffer);
		return (rest);
	}
	return (rest);
}
