#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../get_next_line.h"
#include <string.h>

void show_message(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(0);
}

/* expect return part of the string finishing with\n */
void test_word_part(void) {
    char *tmp = word_copy("joao victor", 4);
    if (strcmp(tmp, "joao") != 0)
        show_message("Error in word_part");
    free(tmp);
    tmp = word_copy("abc", 3);
    if (strcmp(tmp, "abc") != 0)
        show_message("Error in word_part");
    free(tmp);
    tmp = word_copy("abc", 30);
    if (tmp != NULL)
        show_message("Error in word_part");
    tmp = word_copy("abc", -30);
    if (tmp != NULL)
        show_message("Error in word_part");
    tmp = word_copy("abc", 0);
    if (strcmp(tmp, "abc") != 0)
        show_message("Error in word_part");
    puts("word_part: OK");
}
/* expect return each line of the file */
void test_get_next_line(void) 
{
    int fd = open("./nomes.txt", O_RDONLY);
    char *str; 
    while ((str = get_next_line(fd)) != NULL)
    {
        printf(str);
        free(str);
    }
    puts("get-next-line: OK");
}

int main(void) {
    
   // get_next_line(fd);
   //test_word_part();
   test_get_next_line();
}