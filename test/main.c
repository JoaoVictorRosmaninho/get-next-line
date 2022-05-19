#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../get_next_line.h"

int main(void) {
    int fd = open("nomes.txt", O_RDONLY);
    get_next_line(fd);
}