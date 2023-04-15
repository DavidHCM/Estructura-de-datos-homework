#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "datatypes.h"

int main()
{
    FILE *fp;
    fp = fopen("C:\\Users\\david\\Documents\\GitHub\\Estructura-de-datos-class\\Act-repo 20\\Act-1\\prueba.txt", "r");
    char c,*c1;
    STACK STR = stack_create();

    while(!feof(fp))
    {
        c = fgetc(fp);
        if(c == '(' || c == '{' || c == '[')
        {
            printf("%c",c);
            stack_push(STR, char_create(c));
        }
        if(c == ')')
        {
            printf("%c",c);


            c1 = stack_pop(STR);
            if(*c1 != '(')
            {
                fprintf(stderr,"\nSalio mal este pedo 1");
                exit(1);
            }
        }
        else if(c == '}')
        {
            printf("%c",c);
            c1 = stack_pop(STR);
            if(*c1 != '{')
            {
                fprintf(stderr,"\nSalio mal este pedo 2");
                exit(2);
            }
        }
        else if(c == ']')
        {
            printf("%c",c);
            c1 = stack_pop(STR);
            if(*c1 != '[')
            {
                fprintf(stderr,"\nSalio mal este pedo 3");
                exit(3);
            }
        }
    }

    if(stack_empty(STR))
    {
        printf("\nStack vacio");
    }
    else
    {
        printf("\nStack con datos");
    }

    return 0;
}
