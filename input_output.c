#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <zconf.h>
#include "input_output.h"

int make_mass(comment *mass){
    /*int fd = open("file_with_struct.txt", O_RDONLY); // можно fopen + fileno
    struct stat st;
    stat("file_with_struct.txt", &st);
    size_t file_size = st.st_size;
    mass = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
    close(fd);
    munmap(mass, size); */
    return 0;
}