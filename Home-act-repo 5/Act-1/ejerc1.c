#include <stdio.h>
//INTEGRANTES
//DIEGO FERNANDO ZAPATA MARTINEZ
//DAVID HERNANDEZ CAMACHO


//Definimos las dos contantes que usaremos para las dimensiones.
#define R 3
#define C 3


//Funcion que recibe la matriz de dimesiones de 3x3.
int max(int mat[R][C]){
    int sent = -1;
    int *pmat = mat;
    int pcol = *pmat;

    //Ciclo while en el que siempre y cuando el sentinela se diferente del tamaño de la matriz se mantendra abierto.
    while(sent != (sizeof(mat))){

        //Comparacion donde si el apuntador de la matriz es mayor al elemento igualado de la anterior posicion entonces se cumplicara los igueinte.
        //En el que se igualara la posicion actual del apuntador a la anterior y se sumara una iteracion al apuntador.
        if(*pmat > pcol){
            pcol = *pmat;
        }
        //Se suma el sentinela 1 posicion, como tambien el apuntador de la matriz.
        pmat++;
        sent++;
    }

    //Retornamos el valor mas grande.
    return pcol;
}

int main() {

    //Se define la matriz
    int mat[R][C] = {
            { 1, 2, 3},
            { -1, -2, 0 },
            {2, 4, -3 }
                };

    int m = max(mat); // max = 4
    printf("%d\n",m);
    return 0;
}

