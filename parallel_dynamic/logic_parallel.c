#include <sys/mman.h>
#include <stdlib.h>
#include <zconf.h>
#include <sys/wait.h>
#include "logic_parallel.h"
#include "../consist_static/logic_consist.h"

unsigned int counting_records_parallel(comment *mass, int mass_size) {
    int *shared_memory = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *shared_memory = 0;
    comment *a;
    a = mass;
    pid_t pid = fork();
    if (pid == 0) a = mass + mass_size / 4;
    pid_t pid2;
    pid_t pid3;
    if (pid == 0) {
        pid2 = fork();
    }
    if (pid == 0 && pid2 == 0) {
        a = mass + mass_size / 2;
        pid3 = fork();
    }
    if (pid == 0 && pid2 == 0 && pid3 == 0) a = mass + 3 * mass_size / 4;

    for (int i = 0; i < mass_size / 4; i++) {
        if (a[i].average_mark >= 4 && in_quarter(&a[i].last_date))
            *shared_memory = *shared_memory + 1;
        wait(NULL);
    }
    if (pid == 0) exit(10);
   // kill(pid,44);
    int count = *shared_memory;
    munmap(shared_memory, sizeof(int));
    return count;
}