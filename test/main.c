#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../get_next_line.h"
#include <string.h>

/* expect return each line of the file */
void test_get_next_line(void) 
{
    int fd = open("nomes.txt", O_RDONLY);
    char *str = NULL; 
    while ((str = get_next_line(fd)) != NULL)
    {         
         printf("%s", str);
         free(str);
    }
}

int main(void) {
    
   // get_next_line(fd);
  // test_word_part();
   test_get_next_line();
}
