#include "./get_next_line.h"
#include <stddef.h>



char	*alloc_buff(size_t size) 
{
	char *ptr;
        size_t index;

	ptr = (char *) malloc(sizeof(char) * size);
        index = 0;
	if (!ptr)
		return (NULL);
        while (index < size)
          ptr[index++] = '\0';
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_uc;
	unsigned char	*src_uc;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_uc[i] = src_uc[i];
		i++;
	}
	return (dest);
}
