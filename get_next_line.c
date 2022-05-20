#include "./get_next_line.h"
#include <stdio.h>

/*
	E se não tiver nenhum \n ?
*/


char *read_lines(char *buffer) {
	char *pos_char;
	static int fixed_position = 0;
	
	pos_char = ft_strchr(buffer + fixed_position + 1, '\n');
	if (!pos_char) 
		return (NULL);
	fixed_position = (int) (buffer - pos_char);
	return (word_copy(buffer, fixed_position));
	
}

char *get_next_line(int fd) 
{
	static char *buffer;
	ssize_t bytes_read;

	buffer = alloc_buff(BUFFER_SIZE + 1);
	if (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		return (read_lines(buffer));
	}
	free(buffer);
	return (NULL);
}
