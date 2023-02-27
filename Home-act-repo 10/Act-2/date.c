//
// Created by David on 24/02/2023.
//

#include "date.h"

DATE date_create(int days,int months,int years)
{
    DATE d1 = malloc(sizeof(struct DATES));

    if(d1 == NULL)
    {
        fprintf(stderr,"No se pudo alocar la memoria");
    }
    else
    {
        if(days <= 31 && days >= 1)
        {
            if(months <= 12 && months >= 1)
            {
                if(years <= 9999 && years >= 1)
                {
                    d1->day = days;
                    d1->month = months;
                    d1->year = years;
                }
                else
                {
                    d1->day = 01;
                    d1->month = 01;
                    d1->year = 1970;
                }
            }
            else
            {
                d1->day = 01;
                d1->month = 01;
                d1->year = 1970;
            }
        }
        else
        {
            d1->day = 01;
            d1->month = 01;
            d1->year = 1970;
        }
    }
    return (d1);
}

void date_add(DATE d1,int days)
{
    switch (d1->month) {
        case 1:
            d1->day += days;
            if (d1->day > 31) {
                d1->day -= 31;
                d1->month += 1;
                if (d1->month > 12) {
                    d1->month = 1;
                    d1->year += 1;
                }
            }
            break;
        case 3:
            d1->day += days;
            if (d1->day > 31) {
                d1->day -= 31;
                d1->month += 1;
                if (d1->month > 12) {
                    d1->month = 1;
                    d1->year += 1;
                }
            }
            break;
        case 5:
            d1->day += days;
            if (d1->day > 31) {
                d1->day -= 31;
                d1->month += 1;
                if (d1->month > 12) {
                    d1->month = 1;
                    d1->year += 1;
                }
            }
            break;
        case 7:
            d1->day += days;
            if (d1->day > 31) {
                d1->day -= 31;
                d1->month += 1;
                if (d1->month > 12) {
                    d1->month = 1;
                    d1->year += 1;
                }
            }
            break;
        case 8:
            d1->day += days;
            if (d1->day > 31) {
                d1->day -= 31;
                d1->month += 1;
                if (d1->month > 12) {
                    d1->month = 1;
                    d1->year += 1;
                }
            }
            break;
        case 10:
            d1->day += days;
            if (d1->day > 31) {
                d1->day -= 31;
                d1->month += 1;
                if (d1->month > 12) {
                    d1->month = 1;
                    d1->year += 1;
                }
            }
            break;
        case 12:
            d1->day += days;
            if (d1->day > 31) {
                d1->day -= 31;
                d1->month += 1;
                if (d1->month > 12) {
                    d1->month = 1;
                    d1->year += 1;
                }
            }
            break;

        case 2:
            if (d1->year % 4 == 0 && d1->year % 100 != 0 || d1->year % 400 == 0) {
                d1->day += days;
                if (d1->day > 29) {
                    d1->day -= 29;
                    d1->month += 1;
                    if (d1->month > 12) {
                        d1->month = 1;
                        d1->year += 1;
                    }
                }
            }
            else
            {
                d1->day += days;
                if (d1->day > 28) {
                    d1->day -= 28;
                    d1->month += 1;
                    if (d1->month > 12) {
                        d1->month = 1;
                        d1->year += 1;
                    }
                }
            }

            break;

                case 4:
                    d1->day += days;
                if (d1->day > 30) {
                    d1->day -= 30;
                    d1->month += 1;
                    if (d1->month > 12) {
                        d1->month = 1;
                        d1->year += 1;
                    }
                }
                break;
                case 6:
                    d1->day += days;
                if (d1->day > 30) {
                    d1->day -= 30;
                    d1->month += 1;
                    if (d1->month > 12) {
                        d1->month = 1;
                        d1->year += 1;
                    }
                }
                break;
                case 9:
                    d1->day += days;
                if (d1->day > 30) {
                    d1->day -= 30;
                    d1->month += 1;
                    if (d1->month > 12) {
                        d1->month = 1;
                        d1->year += 1;
                    }
                }
                break;
                case 11:
                    d1->day += days;
                if (d1->day > 30) {
                    d1->day -= 30;
                    d1->month += 1;
                    if (d1->month > 12) {
                        d1->month = 1;
                        d1->year += 1;
                    }
                }
                break;
            }
}


void date_sub(DATE d1,int days)
{
    switch (d1->month) {
        case 1:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 30;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
        case 3:
            if (d1->year % 4 == 0 && d1->year % 100 != 0 || d1->year % 400 == 0) {
                d1->day -= days;
                if (d1->day < 1) {
                    d1->day += 29;
                    d1->month -= 1;
                    if (d1->month < 1) {
                        d1->month = 12;
                        d1->year -= 1;
                    }
                }
            }
            else
            {
                d1->day -= days;
                if (d1->day < 1) {
                    d1->day += 28;
                    d1->month -= 1;
                    if (d1->month < 1) {
                        d1->month = 12;
                        d1->year -= 1;
                    }
                }
            }
            break;
        case 5:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 31;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
        case 7:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 31;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
        case 8:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 31;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
        case 10:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 31;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
        case 12:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 31;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;

        case 2:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 31;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;

        case 4:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 30;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
        case 6:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 30;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
        case 9:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 30;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
        case 11:
            d1->day -= days;
            if (d1->day < 1) {
                d1->day += 30;
                d1->month -= 1;
                if (d1->month < 1) {
                    d1->month = 12;
                    d1->year -= 1;
                }
            }
            break;
    }
}

void date_print(DATE d1)
{
    printf("{\n");
    printf("\t\"Day\":%d,\n",d1->day);
    printf("\t\"Month\":%d,\n",d1->month);
    printf("\t\"Year\":%d\n",d1->year);
    printf("}\n");
}

void date_destroy(DATE d1)
{
    free(d1);
}
