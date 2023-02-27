//
// Created by David on 24/02/2023.
//

#ifndef ACTIVIDAD_9_1_DATE_H
#define ACTIVIDAD_9_1_DATE_H
#include <stdio.h>
#include <stdlib.h>

struct DATES{
    int day;
    int month;
    int year;
};

typedef struct DATES * DATE;

DATE date_create(int day,int month,int year);
void date_add(DATE d1,int days);
void date_sub(DATE d1,int days);
void date_print(DATE d1);
void date_destroy(DATE d1);

#endif //ACTIVIDAD_9_1_DATE_H
