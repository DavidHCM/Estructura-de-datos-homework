#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "datatypes.h"




int main() {
    STACK s1 = stack_create();
    int *arr = malloc(sizeof (int ));
    int j,k=0;
    int *num,*test;

    while(1)
    {
        printf("Dame un numero (0 para terminar):");
        scanf("%d",&j);

        if(j!=0)
        {
            arr = realloc(arr,(k+1) * sizeof (int));
            arr[k] = j;
            k++;
        }
        else
        {
            break;
        }
    }

    for(int i=0;i<k;i++)
    {
        stack_push(s1,int_create(arr[i]));
    }

    test = stack_peek(s1);
    printf("El tope del stack es: %d\n",*test);

    while(!stack_empty(s1))
    {
        num = stack_pop(s1);
        printf("%d\n",*num);
    }

    stack_destroy(s1);

    return 0;
}
