#ifndef HOMEWORK2_INPUT_OUTPUT_H
#define HOMEWORK2_INPUT_OUTPUT_H

enum Mark{MARK_1=1, MARK_2, MARK_3, MARK_4, MARK_5};

typedef struct{
    unsigned short int year;
    unsigned short int month;
    unsigned short int day;
} Date;

typedef struct{
   unsigned int id;
   unsigned short int voice;
   Date last_date;
   float average_mark;
   enum Mark mark;
} comment;

#endif //HOMEWORK2_INPUT_OUTPUT_H
