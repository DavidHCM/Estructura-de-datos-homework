#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// I N T E G R A N T E S
//Victor Sebastian Huerta Silva
//David Hernández Camacho

#define CONS 64

int main() {
    int *ptr = NULL,i;
    //Imprimimos la direccion donde apunta en NULL.
    printf("Apuntando inicial de ptr en NULL: %p\n",ptr);

    //Creamos un apuntador que aloca una memoria de 64 elementos con un tamaño de int o 4 bytes.
    ptr = calloc(CONS ,sizeof(int));

    //Solo comprobamos si en el caso de que no se pudiera alocar la memoria y que regresara null lo ubicaramos.
    if(ptr == NULL){
        fprintf(stderr,"Fallo asignacion de memeoria");
        exit(1);
    }
    //Indicamos en el ciclo que en el elemento 10 del array ponga un valor de 5000. Al igual que tambien imprimimos el array.
    for(i=0;i<CONS;i++){

        if(i == 10){
            ptr[i] = 5000;
        }
        printf("%d: %d\t",i,ptr[i]);
    }

    //Imprimimos la posicion inicial del array antes de liberar memoria.
    printf("\nMemoria inicial antes de liberarla apuntando al primer elemento: %p\n",ptr);
    free(ptr);
    //Imprimimos la posicion inicial del array despues de liberar memoria.
    //Y donde podemos ver que mantiene la misma direccion
    printf("Memoria final despues de liberarla: %p\n",ptr);
    //Aqui un parentesis pequeño, me sale un warning en el ptr y lo investigue que es por que ptr podria apuntar a memoria desasignado.


    /*
     * ¿Cuál es la razón de cambio entre cada dirección impresa?
     * La razon de cambio de direccion es por el tamaño del dato que estamos mandando, que es un int de 4 bytes.
     *
     * Si le pido que muestre la dirección de memoria apuntada por ptr ¿Qué imprime el programa?
     * Antes y despues de liberar la memoria este imprime donde apunta la direccion del primer elemento, esto es antes y despues de haberlo liberado
     * siendo despues de liberarlo si mantiene el primer lugar donde estaria un elemento mas que no los elementos del array.
     */

    return 0;
}
