#ifndef GNL_H

# define GNL_H
# include <unistd.h>
# include <stdlib.h>

void	*ft_calloc(size_t COUNT, size_t ELTSIZE);
char    *get_next_line(int fd); 
char	*ft_strchr(const char *STRING, int C);
size_t	ft_strlen(const char *S);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
