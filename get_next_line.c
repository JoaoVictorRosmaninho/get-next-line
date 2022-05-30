#include "./get_next_line.h"
#include <stdio.h>

/*
	E se não tiver nenhum \n ?
*/


char *read_lines(char **buffer, char *f) {
	char *pos_char;
	int fixed_position;
	int size;
	char *tmp;
	
	pos_char = ft_strchr(*buffer, '\n');
	size = ft_strlen(*buffer);
	if (size > 0) 
	{
		if (!pos_char) 
		{
			tmp = ft_strdup(*buffer);
			ft_memcpy(*buffer, "\0", BUFFER_SIZE);
			return (tmp); 
		}
		*f = 0;
		fixed_position = (int) (pos_char - *buffer);
		tmp = word_copy(*buffer, fixed_position + 1);
		ft_memcpy(*buffer, (*buffer + fixed_position + 1), size - fixed_position+ 1);
	}
	 return (tmp);
}

char *get_next_line(int fd) 
{
	static char *buffer = NULL;
	char *rest;
	char flag;
	char *ptr_aux_a;
	char *ptr_aux_b;

	if (!buffer)
		buffer = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
	rest = NULL;
	flag = 1;
	while (1)
	{
		if (ft_strlen(buffer) > 0)
			 ptr_aux_a = read_lines(&buffer, &flag);
		else 
		{
			if (read(fd, buffer, BUFFER_SIZE) < 1)
				break ;
			buffer[BUFFER_SIZE] = '\0';
			ptr_aux_a = read_lines(&buffer, &flag);
		}
		if (!rest)
			rest = ptr_aux_a; 
		else
		{   
			ptr_aux_b = rest; 
			rest = ft_strjoin(rest, ptr_aux_a);
			free(ptr_aux_a);
			free(ptr_aux_b);
		}
		if (!flag)
			return rest; 
	}
	free(buffer);
	return NULL;
}