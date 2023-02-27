#include <stdio.h>
//INTEGRANTES
//DIEGO FERNANDO ZAPATA MARTINEZ
//DAVID HERNANDEZ CAMACHO


//Definicion de una funcion void donde recibe el numero de renglones de la matriz y el doble apuntador la matriz.
void arrtolower(char **words,int R){
    int i,j;

    //Igualamos el doble apuntador a la matriz.
    char **pren = words;
    char *pcol;

    for(i=0;i<1;i++){
        //Igualamos un apuntador a el apuntador que ya almacena la matriz.
        pcol = *pren;

        //Ciclo for en el que recorro cada elemento del arreglo.
        for(j=0;j<40;j++){

            //El proposito de este if es en el que el si el elemento que apunta pcol es menor a 65 se salta de lugar.
            //El proposito de este if es si es que hay algun numero en la parte del arreglo lo ignore.
            if(*pcol < 65){
                pren++;
            }
            //El proposito de este if es para hacer una comparacion para saber si ya hay algun elemento del arreglo que ya este en minusculas.
            //Donde de ser asi se termina ignorando la iteracion y se mueve un lugar del apuntador.
            //De lo contrario cambiaria el caracter a uno sin sentido.
            else if((*pcol >= 97) && (*pcol <= 122)){
                pren++;

            }
            //El proposito de esta comparacion en el if es solo para saber si el elemtno al que esta apuntado esta entre el intervalo de caracteres de mayusculas para cambiarlo a minusculas.
            else if((*pcol >= 65) && (*pcol <= 90 )){
                *pcol += 32;

            }
            //Imrpimir los caracteres.
            printf("%c",*pcol);

            //Se mueve un lugar en el apuntador si todo sale bien.
            pcol++;
        }
        //Se mueve un lugar de el array en el apuntador al acabar la iteracion.
        pren++;

    }
}


int main() {
    //Definicion del arreglo.
    char words[][10] = {"HOLA", "MUNDO", "Cruel5", "ADIOS"};
    //Igualacion con un apuntador donde indicamos el apuntador y despues de cada palabra.
    char *pwords[] = {words,words + 9,words+18,words+32};
    arrtolower(pwords, 4); // words  { “hola”, “mundo”, “cruel5”, “adiÓs” }


    return 0;
}
