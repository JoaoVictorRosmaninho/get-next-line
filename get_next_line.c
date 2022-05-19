#include "./get_next_line.h"
#include <stdio.h>

/*
	E se não tiver nenhum \n ?
*/

char *readlines(char **rest, char *buffer) {
	char *tmp;
	
	tmp = ft_strchr(buffer, '\n');
	if (!tmp) 
		return (NULL);
	return ft_strtrim(buffer, tmp);
}


char *get_next_line(int fd) 
{
	char *buffer;
	static char *rest;
	ssize_t bytes_read;

	buffer = alloc_buff(BUFFER_SIZE + 1);
	if (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		//read_lines(buffer, &rest)
		puts(buffer);
	}
	free(buffer);
	return (NULL);
}
