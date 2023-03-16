#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "datatypes.h"

int main() {

    STACK s1 = stack_create();
    char *str;
    char num[10];


    printf("Ingresa una cadena de caracteres: ");
    scanf("%s",num);


    for(int i = 0 ; i< strlen(num);i++)
    {
        stack_push(s1,char_create(num[i]));
    }

    while(!stack_empty(s1))
    {
        str = stack_pop(s1);
        printf("%c",*str);
    }

    stack_destroy(s1);


    return 0;
}
