/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:53:09 by jv                #+#    #+#             */
/*   Updated: 2022/06/12 17:41:52 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stddef.h>

void	*ft_memset(void *BLOCK, int C, size_t SIZE)
{
	unsigned char		value;
	size_t				index;

	value = (unsigned char) C;
	index = 0;
	while (index < SIZE)
	{
		*(((unsigned char *) BLOCK) + index) = value;
		index++;
	}
	return (BLOCK);
}

size_t	ft_strlen(const char *S)
{
	char *tmp = NULL;

    if (!S)
		return (0);
	tmp = (char*) S;
	while (*tmp)
		tmp++;
	return ((size_t) (tmp - S));
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
	size_t	size_a;
	size_t	size_b;

	if (!s1 || !s2)
		return (NULL);
	size_a = ft_strlen(s1);
	size_b = ft_strlen(s2);
	size = size_a + size_b + 1;
	new_str = (char *) malloc(size);
	ft_memset(new_str, 0, size);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, size_a);
	ft_memcpy(new_str + size_a, s2, size_b);
	return (new_str);
}
