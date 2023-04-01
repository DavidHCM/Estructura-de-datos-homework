
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
        printf("%d\t",*n);
    }

    printf("\nRecorriendo hacia atras: \n");
    iterator = list_end(l1);
    while(list_has_prior(iterator))
    {
        iterator = list_prior(iterator);
        n = iterator->elem;
        printf("%d\t",*n);
    }

    //----------Prueba eliminando el elemento 5-----------
    int position_to_remove = 1;
    printf("\n\nRemover elemento %d\n", position_to_remove);

    //Remover la posición
    iterator = list_begin(l1);
    for (int i = 0; i <= position_to_remove; i++)
    {
        iterator = list_next(iterator);
    }
    list_remove(iterator);

    //-------------Prueba volver a pasar la lista-----------
    printf("\nPrueba pasando todos los elementos despues de remover\n");
    iterator = list_begin(l1);
    while(list_has_next(iterator))
    {
        iterator = list_next(iterator);
        n = iterator->elem;
        printf("%d\t",*n);
    }

	list_destroy(l1);
}

