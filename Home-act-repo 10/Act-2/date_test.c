#include <stdio.h>
#include "date.h"

int main() {
    DATE d1 = date_create(1,3,2003);

    //date_add(d1,5);
    date_sub(d1,1);
    date_print(d1);
    date_destroy(d1);

    return 0;
}
