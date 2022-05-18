#ifndef GNL_H

# define GNL_H
# include <unistd.h>
# include <stdlib.h>

char *alloc_buff(size_t size);
char *get_next_line(int fd); 

#endif
