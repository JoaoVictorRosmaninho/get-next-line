#include "./get_next_line.h"
#include <stddef.h>


void	*ft_calloc(size_t COUNT, size_t ELTSIZE)
{
	void	*ptr;
	int i;

	ptr = malloc(COUNT * ELTSIZE);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (COUNT * ELTSIZE)) {
		*(unsigned char * )(ptr + i) = 0;
		i++;
	}
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*new_str;
        size_t  size_a;
        size_t  size_b;

	if (!s1 || !s2)
		return (NULL);

	size_a = ft_strlen(s1); 
        size_b = ft_strlen(s2); 
        size = size_a + size_b + 1;
	new_str = (char *) ft_calloc(size, 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, size_a); 
	ft_memcpy(new_str + size_a, s2, size_b); 
	new_str[size] = '\0'; 
        return (new_str);
}

char	*ft_strdup(const char *str)
{
	size_t		size_buffer;
	char		*new_str;

	size_buffer = ft_strlen(str) + 1;
	new_str = (char *) malloc(size_buffer);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str, size_buffer);
	return (new_str);
}




