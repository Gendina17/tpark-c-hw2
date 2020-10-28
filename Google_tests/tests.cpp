#include "gtest/gtest.h"
extern "C" {
#include "../consist_static/logic_consist.h"
#include "../parallel_dynamic/logic_parallel.h"
}
#define test_size 20
TEST(Date_test, test1) { // тествание функции проверки квартала(входит в квартал)
    Date d1={2020, 8, 30};
    Date d2={2020, 10, 22};
    Date d3={2020, 9, 5};
    EXPECT_TRUE(in_quarter(&d1));
    EXPECT_TRUE(in_quarter(&d2));
    EXPECT_TRUE(in_quarter(&d3));
}


TEST(Date_test, test2) {//тествание функции проверки квартала(не входит в квартал)
    Date d1={1990, 8, 30};
    Date d2={2020, 7, 20};
    Date d3={2021, 3, 5};
    EXPECT_FALSE(in_quarter(&d1));
    EXPECT_FALSE(in_quarter(&d2));
    EXPECT_FALSE(in_quarter(&d3));
}

#define def 1
#define def_year 1900
TEST(counting, test1) {//тест правильности подсчета записей, если такие имеются
    comment mass[test_size];
    int val=0;
    time_t now = time(nullptr);
    struct tm *ltm = localtime(&now);
    for(int i=0;i<test_size;i++){
        mass[i].id=def;
        mass[i].mark=MARK_1;
        mass[i].voice=def;
        if(i%2==0){
            mass[i].average_mark=4.5;
            mass[i].last_date.year=def_year + ltm->tm_year;
            mass[i].last_date.month=1 + ltm->tm_mon;
            mass[i].last_date.day=ltm->tm_mday-i;
            val++;
        } else{
            mass[i].average_mark=1;
        }
    }
    EXPECT_EQ(val,counting_records(mass, test_size));
}

TEST(counting, test2) {//тест правильности подсчета записей, если таких нет
    comment mass[test_size];
    for(auto & mas : mass){
        mas.id=def;
        mas.mark=MARK_1;
        mas.voice=def;
        mas.last_date={def,def,def};
        mas.average_mark=def;
    }
    EXPECT_EQ(0,counting_records(mass, test_size));
}

TEST(parallel_counting, test1) { //тест правильности подсчета записей(параллельно), если такие есть
    comment mass[20];
    int val=0;
    time_t now = time(nullptr);
    struct tm *ltm = localtime(&now);
    for(int i=0;i<5;i++){
        mass[i].id=def;
        mass[i].mark=MARK_1;
        mass[i].voice=def;
        if(i%2==0){
            mass[i].average_mark=4.5;
            mass[i].last_date.year=def_year + ltm->tm_year;
            mass[i].last_date.month=1 + ltm->tm_mon;
            mass[i].last_date.day=ltm->tm_mday-i;
            val++;
        } else{
            mass[i].average_mark=1;
        }
    }
    EXPECT_EQ(val,counting_records_parallel(mass, test_size));
}

TEST(parallel_counting, test2) { //тест правильности подсчета записей(параллельно), если таких нет
    comment mass[test_size];
    for(auto & mas : mass){
        mas.id=def;
        mas.mark=MARK_1;
        mas.voice=def;
        mas.last_date={def,def,def};
        mas.average_mark=def;
    }
    EXPECT_EQ(0,counting_records_parallel(mass, test_size));
}


TEST(Stress_test, test1) {     //стресс тест проверка равенства ответов при параллельном и последовательном методе
comment *mass=(comment*)calloc(50*test_size, sizeof(comment));
    int val=0;
    time_t now = time(nullptr);
    struct tm *ltm = localtime(&now);
    for(int i=0;i<5;i++){
        mass[i].id=def;
        mass[i].mark=MARK_1;
        mass[i].voice=def;
        if(i%2==0){
            mass[i].average_mark=4.5;
            mass[i].last_date.year=def_year + ltm->tm_year;
            mass[i].last_date.month=1 + ltm->tm_mon;
            mass[i].last_date.day=ltm->tm_mday-i;
            val++;
        } else{
            mass[i].average_mark=1;
        }
    }
    EXPECT_EQ(val,counting_records_parallel(mass, 50*test_size));
    EXPECT_EQ(val,counting_records(mass, 50*test_size));
    EXPECT_EQ(counting_records(mass,50*test_size),counting_records_parallel(mass, 50*test_size));
    free(mass);
}
