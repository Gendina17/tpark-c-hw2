#include "logic_consist.h"
#include <bits/types/time_t.h>
#include <time.h>
#include <stdlib.h>

#define hour_quarter 2160
#define def_year 1900

unsigned int counting_records(comment *mass, int mass_size) {
    if (mass_size == 0)return 0;
    int count = 0;
    for (int i = 0; i < mass_size; i++) {
        if (mass[i].average_mark >= 4 && in_quarter(&mass[i].last_date))
            count++;
    }
    return count;
}

bool in_quarter(Date *date) {
    time_t now = time(NULL);
    struct tm *ltm = localtime(&now);
    Date current_date = {def_year + ltm->tm_year, 1 + ltm->tm_mon, 0 + ltm->tm_mday};
    if (current_date.year - date->year >= 2) return false;
    int current_time = ((current_date.year - def_year) * 365 + (current_date.month) * 30 + current_date.day) * 24;
    int comment_time = ((date->year - def_year) * 365 + (date->month) * 30 + date->day) * 24;
    return abs(current_time - comment_time) <= hour_quarter ? true : false;
}
