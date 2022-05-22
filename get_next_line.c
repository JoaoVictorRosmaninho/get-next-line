#include "./get_next_line.h"
#include <stdio.h>

/*
	E se não tiver nenhum \n ?
*/


char *read_lines(char **buffer) {
	char *pos_char;
        int fixed_position;
        int size;
        char *tmp;
	
	pos_char = ft_strchr(*buffer, '\n');
        size = ft_strlen(*buffer);
        if (size > 0) 
        {
	  if (!pos_char)
            pos_char = ft_strchr(*buffer, '\0');
	  fixed_position = (int) (pos_char - *buffer);
          tmp = word_copy(*buffer, fixed_position);
          if (*pos_char != '\0')
            ft_memcpy(*buffer, (*buffer + fixed_position + 1), size - fixed_position+ 1);
          else 
          {
            free(*buffer);
            *buffer = NULL;
          }
	  return (tmp);
        }
       return (NULL);
	
}

char *get_next_line(int fd) 
{
	static char *buffer = NULL;
	ssize_t bytes_read;

	if (!buffer)
          buffer = alloc_buff(BUFFER_SIZE + 1);
	if (ft_strlen(buffer) < 1 && read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		return (read_lines(&buffer));
	}
        if (buffer != NULL) 
          return (read_lines(&buffer));
	return (NULL);
}
