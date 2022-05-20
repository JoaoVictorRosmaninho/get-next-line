#ifndef GNL_H

# define GNL_H
# include <unistd.h>
# include <stdlib.h>

char *alloc_buff(size_t size);
char *get_next_line(int fd); 
char *word_copy(char *str, size_t size);
char	*ft_strchr(const char *STRING, int C);

#endif
