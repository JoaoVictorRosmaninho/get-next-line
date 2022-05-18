#include "./get_next_line.h"



char	*alloc_buff(size_t size) 
{
	char *ptr;

	ptr = (char *) malloc(sizeof(char) * size	);
	if (!ptr)
		return (NULL);
	return (ptr);
}
