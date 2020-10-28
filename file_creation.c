#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input_output.h"

void file_creation(){
    srand(time(NULL));
    comment my_struct;
    time_t now = time(NULL);
    struct tm *ltm = localtime(&now);
    Date current_date={1900 + ltm->tm_year,1 + ltm->tm_mon,0 + ltm->tm_mday};
    FILE *f;
    f = fopen("file_with_struct.txt", "w+b");
    for (int i = 0; i < 10000000; i++) {
            my_struct.id = rand();
            my_struct.mark = rand() % 5 + 1;
            my_struct.voice = rand() % 1000;
            if (i % 20 == 0) {
                my_struct.last_date.year = current_date.year;
                my_struct.last_date.month = current_date.month - rand() % 3;
                my_struct.last_date.day = current_date.day - rand() % 10;
                int y = rand() % 10;
                my_struct.average_mark = 4 + 0.1 * y;
            } else {
                my_struct.last_date.day = rand() % 31 + 1;
                my_struct.last_date.month = rand() % 12 + 1;
                my_struct.last_date.year = 1990 + rand() % 20;
                my_struct.average_mark = rand() % 5 + 0.1 * (i % 10);
            }
            fwrite(&my_struct, sizeof(my_struct), 1, f);

    }
        fclose(f);

}