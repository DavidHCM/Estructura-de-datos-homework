/*
 * ejemplolista.c
 *
 *  Created on: 24 mar. 2023
 *      Author: jluis
 */
#include <stdio.h>
#include "list.h"

int main()
{
	LIST l1=list_create();
	int *n;
	int i;
    ITERATOR iterator;

	for(i=0;i<10;i++)
    {
        list_add(l1,int_create(i));
    }

    printf("Recorriendo hacia adelante: \n");
    iterator = list_begin(l1);
    while(list_has_next(iterator))
    {
        iterator = list_next(iterator);
        n = iterator->elem;
        printf("%d\n",*n);
    }

    printf("\nRecorriendo hacia atras: \n");
    iterator = list_end(l1);
    while(list_has_prior(iterator))
    {
        iterator = list_prior(iterator);
        n = iterator->elem;
        printf("%d\n",*n);
    }

	list_destroy(l1);
}

