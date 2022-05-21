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

size_t	ft_strlen(const char *S)
{
	size_t	size;

	size = 0;
	while (S[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *STRING, int C)
{
	size_t	index;

	index = 0;
	while (STRING[index])
	{
		if ((unsigned char ) STRING[index] == (unsigned char ) C)
			return (((char *) STRING) + index);
		index++;
	}
	if ((unsigned char ) STRING[index] == (unsigned char ) C)
		return (((char *) STRING) + index);
	return (NULL);
}

char *word_copy(char *str, size_t size) 
{
	char *word_part;
	int index;

	if (size < 0 || size > ft_strlen(str))
		return (NULL);
	if (size == 0)
		size = ft_strlen(str);
	index = 0;
	word_part = (char *) malloc(size + 1);
	while (*str && index < size)
		word_part[index++] = *str++;
	word_part[index] = '\0';
	return (word_part);
}
