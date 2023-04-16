#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "datatypes.h"

int main()
{
    FILE *fp;
    fp = fopen("C:\\Users\\David\\Documents\\GitHub\\Estructura-de-datos-homework\\Home-act-repo 21\\Act-1\\fuente.txt", "r");
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
                fprintf(stderr,"\nSalio algo mal, flag: 1");
                exit(1);
            }
        }
        else if(c == '}')
        {
            printf("%c",c);
            c1 = stack_pop(STR);
            if(*c1 != '{')
            {
                fprintf(stderr,"\nSalio algo mal, flag: 2");
                exit(2);
            }
        }
        else if(c == ']')
        {
            printf("%c",c);
            c1 = stack_pop(STR);
            if(*c1 != '[')
            {
                fprintf(stderr,"\nSalio algo mal, flag: 3");
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
