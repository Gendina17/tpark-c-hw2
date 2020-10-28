#include <stdio.h>
#include <sys/mman.h>
#include <zconf.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "file_creation.h"
#include "input_output.h"
#include "consist_static/logic_consist.h"
#include "parallel_dynamic/logic_parallel.h"

#define mass_size 10000000

/* В вашем распоряжении — массив из 10 млн. структур, содержащих числовой идентификатор записи (комментария)
 * в социальной сети, а также поля с семантикой средней оценки (целое 0 или вещественное от 1,0 до 5,0), числа
 * поданных голосов (неотрицательное целое), даты выставления последней оценки и ее значения (целое от 1 до 5).
 * Составьте наивный алгоритм подсчета записей с оценкой не ниже 4,0, получивших хотя бы одну оценку за последний
 * квартал, а затем реализуйте параллельный алгоритм с использованием нескольких процессов с учетом возможной декомпозиции
 * (разбиения) структуры и выравнивания результатов по линиям кэш-памяти. */

int main() {
    // file_creation();                    //создание нашего файла
    int fd = open("file_with_struct.txt", O_RDONLY);
    struct stat st;
    stat("file_with_struct.txt", &st);
    size_t file_size = st.st_size;
    comment *mass = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd,
                         0); //здание mmap файла с имеющимися структурами
    printf("Count(parallel):  %d",                                //запуск параллельной обработки
           counting_records_parallel(mass, mass_size));
    printf("\nCount(consist):  %d",
           counting_records(mass, mass_size));                           //запуск последовательной обработки
    munmap(mass, file_size);
    close(fd);
    return 0;
}


