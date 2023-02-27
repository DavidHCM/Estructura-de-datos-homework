#include <stdio.h>

//Funcion para intercambio de valores en variables.
void swap(int *pa,int *pb)
{
    int temp; //Varible temporal para almacenar el valor original.
    temp = *pa; //Intercambio del valor temporal.
    *pa = *pb;
    *pb = temp; //Valor regresando a su varible original.
}

int main() {
    int a=35,b=40;
    printf("Sin intercambiar: a=%d, b=%d\n",a,b);
    swap(&a,&b);
    printf("Intercambiado: a=%d, b=%d\n",a,b);
    return 0;
}
