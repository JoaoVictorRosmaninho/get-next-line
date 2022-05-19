#include "./get_next_line.h"
#include <stddef.h>



char	*alloc_buff(size_t size) 
{
	char *ptr;

	ptr = (char *) malloc(sizeof(char) * size	);
	if (!ptr)
		return (NULL);
	return (ptr);
}


char *word_copy(char *str, size_t size) 
{
	char *word_part;
	int index;

	index = 0;
	word_part = (char *) malloc(size + 1);
	while (*str && index < size)
		word_part[index++] = str++;
	word_part[index] = '\0';
	return (word_part);
}
